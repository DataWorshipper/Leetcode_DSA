class Solution:
    def areSentencesSimilar(self, s1: str, s2: str) -> bool:

        arr1 = s1.split()
        arr2 = s2.split()

        if len(arr1) < len(arr2):
            arr1, arr2 = arr2, arr1

        i = 0
        j = 0

        while i < len(arr1) and j < len(arr2):
            if arr1[i] == arr2[j]:
                i += 1
                j += 1
            else:
                break

        i1 = len(arr1) - 1
        j1 = len(arr2) - 1

        while i1 >= 0 and j1 >= 0:
            if arr1[i1] == arr2[j1]:
                i1 -= 1
                j1 -= 1
            else:
                break

        return j > j1