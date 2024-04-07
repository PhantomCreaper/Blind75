class Solution(object):
    def kClosest(self, points, k):
        """
        :type points: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
        if(len(points) is 1):
            return points
        m = len(points)
        n = len(points[0])
        dist = {}
        p=0
        for i, j in points:
            dist[p] = math.sqrt((i**2)+(j**2))
            p+=1

        dist = sorted(dist.items(), key = lambda item: item[1])[:k]

        res = [points[i] for i, j in dist]
        return res
        
