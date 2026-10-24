from pathlib import Path
import sys
import tempfile
import unittest


TOOLS = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(TOOLS))

import pre_push


class PrePushPathTests(unittest.TestCase):
    def test_only_double_star_crosses_a_directory(self):
        paths = [
            "manual/data/ini-keys.yaml",
            "README.md",
            "docs/README.md",
            "docsextra/notes.md",
            "code/rules.cpp",
            "code/sub/rules.cpp",
        ]
        self.assertEqual(
            pre_push.matching_paths(paths, ["manual/**", "README.md", "code/*.cpp"]),
            ["README.md", "code/rules.cpp", "manual/data/ini-keys.yaml"])
        self.assertEqual(pre_push.matching_paths(paths, ["docs/**"]), ["docs/README.md"])

    def test_push_filter_is_read_through_the_yaml_boolean_on_key(self):
        with tempfile.TemporaryDirectory() as folder:
            workflow = Path(folder) / "workflow.yml"
            workflow.write_text(
                "on:\n"
                "  pull_request:\n"
                "    paths: [\"other/**\"]\n"
                "  push:\n"
                "    paths:\n"
                "      - \"manual/**\"\n"
                "      - \"code/**\"\n",
                encoding="utf-8")
            self.assertEqual(pre_push.workflow_paths(workflow), ["manual/**", "code/**"])

    def test_repository_workflow_watches_the_manual(self):
        self.assertTrue(pre_push.matching_paths(
            ["manual/tools/manage.py"], pre_push.workflow_paths()))


if __name__ == "__main__":
    unittest.main()
