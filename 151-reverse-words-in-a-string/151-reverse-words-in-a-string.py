class Solution:
    def reverseWords(self, s: str) -> str:
        s = re.sub(' +', ' ', s)
        a = s.split(" ")
        a.reverse()
        return " ".join(a).strip()