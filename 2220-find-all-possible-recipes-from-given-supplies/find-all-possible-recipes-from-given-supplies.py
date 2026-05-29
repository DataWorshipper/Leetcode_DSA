from collections import defaultdict, deque

class Solution:
    def findAllRecipes(self, recipes, ingredients, supplies):

        indegree = defaultdict(int)
        adj = defaultdict(list)

        for i in range(len(recipes)):
            for ing in ingredients[i]:
                adj[ing].append(recipes[i])
                indegree[recipes[i]] += 1

        q = deque(supplies)

        ans = []

        while q:
            item = q.popleft()

            for recipe in adj[item]:

                indegree[recipe] -= 1

                if indegree[recipe] == 0:
                    ans.append(recipe)
                    q.append(recipe)

        return ans