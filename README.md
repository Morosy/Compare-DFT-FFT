## Compare DFT-FFT

#### DFTとFFTの処理時間を比較

#### ouput_random_singal.py
`[min ~ max]`のランダムなN個の乱数を生成するプログラム．

`input`ディレクトリ内に`signal.csv`として出力．



#### csv_checker.py
`DFT.csv`と`FFT.csv`の内容が完全一致しているかを検証するプログラム．

一致していない場合は一致していない行と列の値を出力する．



## example
#### DFTとFFTの処理時間を計測・比較
``` console
$ python -u output_random_signal.py
Done!

$ gcc DFT.c -o DFT
$ gcc FFT.c -o FFT

$ ./DFT
read file done (N = 32768)
DFT done
output DFT done
DFT execution time: 70.478000

$ ./FFT
read file done (N = 32768)
FFT done
output FFT done
FFT execution time: 0.031000

$ python -u csv_checker.py
2つのCSVファイルは一致しています.
```

#### DFT->iDFTとFFT->iFFTの処理時間を計測・比較
``` console
$ gcc DFTandiDFT.c -o DFTandiDFT
$ gcc FFTandiFFT.c -o FFTandiFFT

$ ./DFTandiDFT
read file done (N = 32768)
DFT done
output DFT done
iDFT done
output iDFT done
DFT execution time: 70.555000
iDFT execution time: 70.896000

$ ./FFTandiFFT
read file done (N = 32768)
FFT done
output FFT done
iFFT done
output iFFT done
FFT execution time: 0.033000
iFFT execution time: 0.001000

$ python -u csv_checker2.py
比較するファイル: output/DFT.csv, output/FFT.csv
2つのCSVファイルは一致しています.
比較するファイル: output/iDFT.csv, output/iFFT.csv
2つのCSVファイルは一致しています.
```
