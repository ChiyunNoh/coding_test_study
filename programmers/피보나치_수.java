class Solution {
    public int solution(int n) {
        int answer = 0;
        if(n==1 || n==2) return 1;
        else {
            for(int i=3; i<=n; i++) {
                answer = (num1+num2)%1234567;
                num1 = num2;
                num2 = answer;
            }
            return answer;
        }
    }
}
