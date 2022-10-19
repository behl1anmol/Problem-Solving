public class Solution {
    public IList<string> TopKFrequent(string[] words, int k) => words
        .GroupBy(w => w)
        .OrderByDescending(g => g.TryGetNonEnumeratedCount(out int c) ? c : g.Count())
        .ThenBy(g => g.Key)
        .Select(g => g.Key)
        .Take(k)
        .ToList();
}