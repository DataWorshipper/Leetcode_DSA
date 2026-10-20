class Solution:
    def maximumPopulation(self, logs: list[list[int]]) -> int:
        mpp=defaultdict(int)
        logs.sort()
        for start,end in logs:
            mpp[start]+=1
            mpp[end]-=1
        pref=0
        m_pref=-float("inf")
        min_year=float("inf")
        for year in sorted(mpp):
            pref+=mpp[year]
            if pref>m_pref:
                m_pref=pref
                min_year=year
            
        return min_year        