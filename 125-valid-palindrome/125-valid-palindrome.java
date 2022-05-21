class Solution {
    public boolean isPalindrome(String s) {
        
        int l = 0;
        String temp = s.replaceAll("[^A-Za-z0-9]", "");
        int r = temp.length() - 1;
        
        while(l <= r) {
            if(Character.toLowerCase(temp.charAt(l)) != Character.toLowerCase(temp.charAt(r))) {
                return false;
            }
            l++;
            r--;
        }
        
        return true;
        
    }
}