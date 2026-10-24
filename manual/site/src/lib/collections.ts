import { getCollection, type CollectionEntry, type CollectionKey } from 'astro:content';

const cache = new Map<CollectionKey, Promise<CollectionEntry<CollectionKey>[]>>();

/**
 * Returns a collection's entries, read once per static build because
 * getCollection deep-copies every entry on each call. Callers may reorder the
 * returned array but must not modify its entries. The development server reads
 * through so content edits appear.
 */
export function cachedCollection<C extends CollectionKey>(name: C): Promise<CollectionEntry<C>[]> {
	if (!import.meta.env.PROD) return getCollection(name);
	let entries = cache.get(name);
	if (!entries) {
		entries = getCollection(name);
		cache.set(name, entries);
	}
	return entries.then((rows) => [...rows] as CollectionEntry<C>[]);
}
