using System;
using System.IO;
using System.Text.RegularExpressions;
using System.Collections.Generic;
using System.Linq;

class LeetCodeProblem
{
    public string Title { get; set; }
    public string Url { get; set; }
}

class Program
{
    static void Main(string[] args)
    {
        // Change this to your local repo root or pass as argument
        string repoRoot = args.Length > 0 ? args[0] : Directory.GetCurrentDirectory();
        string outputCsv = "leetcode_problems.csv";
        var problems = new List<LeetCodeProblem>();

        foreach (var dir in Directory.GetDirectories(repoRoot, "*", SearchOption.AllDirectories))
        {
            string readmePath = Path.Combine(dir, "readme.md");
            if (!File.Exists(readmePath))
                readmePath = Path.Combine(dir, "README.md");
            if (!File.Exists(readmePath))
                continue;

            string readmeContent = File.ReadAllText(readmePath);

            // Look for an <h1> or <h2>...<a href="...">Title</a>...</h1> or <h2>
            // Example: <h1><a href="https://leetcode.com/problems/two-sum/">Two Sum</a></h1>
            var match = Regex.Match(readmeContent, @"<h\d[^>]*>\s*<a\s+href\s*=\s*""([^""]+)""[^>]*>([^<]+)</a>\s*</h\d>", RegexOptions.IgnoreCase);
            if (match.Success)
            {
                problems.Add(new LeetCodeProblem
                {
                    Url = match.Groups[1].Value.Trim(),
                    Title = match.Groups[2].Value.Trim()
                });
            }
        }

        // Write to CSV
        using (var writer = new StreamWriter(outputCsv))
        {
            writer.WriteLine("Title,URL");
            foreach (var p in problems.Distinct().OrderBy(x => x.Title))
            {
                // Escape double quotes in title (rare, but for CSV safety)
                string safeTitle = p.Title.Replace("\"", "\"\"");
                writer.WriteLine($"\"{safeTitle}\",\"{p.Url}\"");
            }
        }

        Console.WriteLine($"Extracted {problems.Count} problems to {outputCsv}");
    }
}