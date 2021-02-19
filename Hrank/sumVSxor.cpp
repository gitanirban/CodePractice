//Sum vs XOR
//https://www.hackerrank.com/challenges/sum-vs-xor/problem

long sumXor(long n) {
    long c = 0;
    while (n) {
        c += n % 2 ? 0 : 1;
        n /= 2;
    }
    c = pow(2, c);
    return c;
}