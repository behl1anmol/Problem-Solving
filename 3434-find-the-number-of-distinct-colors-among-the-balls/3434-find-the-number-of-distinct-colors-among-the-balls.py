class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        distinct_colors = {}
        balls = {}
        ans = []

        for num, color in queries:
            if num in balls:
                prev_color = balls[num]
                distinct_colors[prev_color] -= 1
                if distinct_colors[prev_color] == 0:
                    del distinct_colors[prev_color]

            balls[num] = color
            distinct_colors[color] = distinct_colors.get(color, 0) + 1
            ans.append(len(distinct_colors))

        return ans
