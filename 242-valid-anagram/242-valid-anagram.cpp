class Solution {
    public boolean isAnagram(String s, String t) {
        
        char[] sar = s.toCharArray();
        Arrays.sort(sar);
        String ssorted = String.valueOf(sar);
        
        char[] tar = t.toCharArray();
        Arrays.sort(tar);
        String tsorted = String.valueOf(tar);
        
        return ssorted.equals(tsorted);
        
    }
}