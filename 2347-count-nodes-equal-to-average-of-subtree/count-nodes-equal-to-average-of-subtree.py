class Solution:
    def averageOfSubtree(self, root: TreeNode | None) -> int:

        id = {}
        counter = 0

        def assign(node):
            nonlocal counter

            if not node:
                return

            id[node] = counter
            counter += 1

            assign(node.left)
            assign(node.right)

        assign(root)

        sums = [0] * counter
        counts = [0] * counter

        def get_sum(node):
            if not node:
                return 0

            s = node.val + get_sum(node.left) + get_sum(node.right)
            sums[id[node]] = s

            return s

        def get_count(node):
            if not node:
                return 0

            c = 1 + get_count(node.left) + get_count(node.right)
            counts[id[node]] = c

            return c

        get_sum(root)
        get_count(root)

        ans = 0

        def check(node):
            nonlocal ans

            if not node:
                return

            if sums[id[node]] // counts[id[node]] == node.val:
                ans += 1

            check(node.left)
            check(node.right)

        check(root)

        return ans