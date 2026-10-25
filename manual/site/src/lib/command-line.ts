import { UI } from '../i18n/en.mjs';
import { launchOptions, launchSortKey, type LaunchGroup, type LaunchOption } from './commands';
import { tombstones, type TombstoneRecord } from './data';

export const REMOVED_OPTIONS_SLUG = 'removed-options';

export interface LaunchGroupSection {
	id: LaunchGroup;
	title: string;
	description?: string;
	options: LaunchOption[];
}

function bySwitch(left: LaunchOption, right: LaunchOption): number {
	const a = launchSortKey(left);
	const b = launchSortKey(right);
	return a < b ? -1 : a > b ? 1 : left.id.localeCompare(right.id);
}

/** The groups that hold at least one option, in display order, each sorted by switch. */
export function launchGroupSections(): LaunchGroupSection[] {
	const options = launchOptions();
	const groups = UI.launchGroups as Array<{ id: LaunchGroup; title: string; description?: string }>;
	const sectionIds = new Set<string>([...groups.map((group) => group.id), REMOVED_OPTIONS_SLUG]);
	for (const option of options) {
		if (!groups.some((group) => group.id === option.group)) {
			throw new Error(`Launch option ${option.id}: group ${option.group} has no title in UI.launchGroups`);
		}
		// Each option's anchor shares the page with the section anchors.
		if (sectionIds.has(option.route_id)) {
			throw new Error(`Launch option ${option.id}: anchor #${option.route_id} collides with a section`);
		}
	}
	return groups
		.map((group) => ({ ...group, options: options.filter((option) => option.group === group.id).sort(bySwitch) }))
		.filter((group) => group.options.length > 0);
}

export function removedLaunchOptions(): TombstoneRecord[] {
	return tombstones().filter((record) => record.type === 'command' && record.route.startsWith('/using/command-line/'));
}

/** The switch a removed option was typed as, taken from its tombstone's search aliases. */
export function removedSwitch(record: TombstoneRecord): string {
	return record.search_aliases.find((alias) => /^[-/]/.test(alias)) ?? record.id;
}

export function commandLineHeadings(): Array<{ depth: number; slug: string; text: string }> {
	return [
		...launchGroupSections().map((group) => ({ depth: 2, slug: group.id, text: group.title })),
		...(removedLaunchOptions().length > 0
			? [{ depth: 2, slug: REMOVED_OPTIONS_SLUG, text: UI.commandLine.removed }]
			: []),
	];
}
