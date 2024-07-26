
## 仕様
#### output_random_square.py
実行方法
```
python -u output_random_square.py N
```

``` math
$$2^N 個$$
```
の`[-10.0000 ~ 10.0000]`範囲で乱数を生成して，`output/signal-N.csv`に書き込まれる．

#### FFT_time.c
実行方法
```
gcc FFT_time.c -o FFT_time -lm
./DFT_time <filename>
```
`filename`内のデータでFFTが実行される．

`COMPLEX *FFT_Running(double *, int)`関数の実行時間が`output/FFT_time.csv`に追記される．


#### FFT/time.csv
実行例を掲載



## 実行方法
``` console
$ make
mkdir -p input output
touch output/FFT_time.csv
for number in $(seq 4 25); do \
        python -u output_random_square.py $number; \
done
16 done
32 done
64 done
128 done
256 done
512 done
1024 done
2048 done
4096 done
8192 done
16384 done
32768 done
65536 done
131072 done
262144 done
524288 done
1048576 done
2097152 done
4194304 done
8388608 done
16777216 done
33554432 done
rm -f output/FFT_time.csv; \
make FFT_time

for number in $(seq 4 25); do \
        ./FFT_time input/signal-$number.csv; \
done
input/signal-4.csv done
input/signal-5.csv done
input/signal-6.csv done
input/signal-7.csv done
input/signal-8.csv done
input/signal-9.csv done
input/signal-10.csv done
input/signal-11.csv done
input/signal-12.csv done
input/signal-13.csv done
input/signal-14.csv done
input/signal-15.csv done
input/signal-16.csv done
input/signal-17.csv done
input/signal-18.csv done
input/signal-19.csv done
input/signal-20.csv done
input/signal-21.csv done
input/signal-22.csv done
input/signal-23.csv done
input/signal-24.csv done
input/signal-25.csv done
```
