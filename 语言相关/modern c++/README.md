### Promotio and truncation

* Promotion to a larger type keeps the sign

```
int16_t x = -1;
int y = x; // sign extend
cout << y; // print -1
```


* Truncation to a smaller type is implemented as a modulo operation with respect to
the number of bits of the smaller type

```
int x = 65537; // 2ˆ16 + 1
int16_t y = x; // x % 2ˆ16
cout << y; // print 1
int z = 32769; // 2ˆ15 + 1 (does not fit in a int16_t)
int16_t w = z; // (int16_t) (x % 2ˆ16 = 32769)
cout << w; // print -32767
```