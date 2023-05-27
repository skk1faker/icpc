x = gcd(a,b,c)
表示为 max{x    ( x | a, x | b ,x | c)}


其中满足x | a ,x | b, x | c的值一定满足 x | gcd(a,b,c)


否则，
$$ 
a = k_1 gcd(a,b,c)\\
b = k_2 gcd(a,b,c)\\
c = k_3 gcd(a,b,c)\\
$$ 
则 
$$
x | k_1 gcd(a,b,c) \\
x | k_2 gcd(a,b,c) \\ 
x | k_3 gcd(a,b,c) \\
$$
若x不能整除gcd(a,b,c)，则会有

$$
x | k_1 \\
x | k_2 \\
x | k_3 \\

k_1 = k_4 \times  x \\
k_2 = k_5 \times  x \\
k_2 = k_6 \times  x \\
$$

于是
$$
a = k_4 \times x \times gcd(a,b,c) \\
b = k_5 \times x \times gcd(a,b,c) \\
c = k_6 \times x \times gcd(a,b,c) \\
$$

于最大公因数的定义不相符。

