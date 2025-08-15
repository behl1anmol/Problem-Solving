public class Solution {
    private readonly new Dictionary<int, string> romanConstants = new Dictionary<int, string>() 
    {
        {1, "I"},
        {5, "V"},
        {10, "X"},
        {50, "L"},
        {100, "C"},
        {500, "D"},
        {1000, "M"},
        { 4, "IV" },
        { 9, "IX" },
        { 40, "XL" },
        { 90, "XC" },
        { 400, "CD" },
        { 900, "CM" },
        { 2, "II" },
        { 3, "III" }
    };

    private List<int> ReturnBrokenNum(int num)
    {
        var brokenNum = new List<int>();
        int i = 0;

        while(num > 0)
        {
            brokenNum.Add(ReturnPlaceValue(num%10, i));
            i++;
            num = num/10;
        }

        return brokenNum;
    }

    private int ReturnPlaceValue(int num, double pow)
    {
        return (int)Math.Pow(10,pow) * num;
    }
    
    private void CreateRoman(int i1, StringBuilder stringBuilder)
    {
        if (romanConstants.ContainsKey(i1))
        {
            stringBuilder.Append(romanConstants[i1]);
        }
        else
        {
            var maxSymbol = romanConstants.Keys.Where(x => x < i1).Max();
            stringBuilder.Append(romanConstants[maxSymbol]);
            i1 -= maxSymbol;
            CreateRoman(i1, stringBuilder);
        }
    }
    public string IntToRoman(int num) 
    {
        var roman = new StringBuilder();
        CreateRoman(num, roman);
        return roman.ToString();
    }
}