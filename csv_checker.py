import csv

def csv_compare(file1, file2):
    print(f"比較するファイル: {file1}, {file2}")
    with open(file1, 'r') as f1, open(file2, 'r') as f2:
        csv1 = list(csv.reader(f1))
        csv2 = list(csv.reader(f2))

        if len(csv1) != len(csv2):
            print("2つのCSVファイルは一致していません.")
            return False

        for i, (row1, row2) in enumerate(zip(csv1, csv2)):
            if i == 0:  # ラベル行の比較
                if row1 != row2:
                    print(f"行 {i+1} (ラベル行) が一致しません：")
                    print(f"ファイル1: {row1}")
                    print(f"ファイル2: {row2}")
                    return False
            else:  # 数値行の比較
                for j, (val1, val2) in enumerate(zip(row1, row2)):
                    # -0.0と0.0を同じ値として扱う
                    if float(val1) != float(val2) and not (float(val1) == 0.0 and float(val2) == 0.0):
                        print(f"行 {i+1}, 列 {j+1} が一致しません：")
                        print(f"ファイル1: {val1}")
                        print(f"ファイル2: {val2}")
                        return False

        print("2つのCSVファイルは一致しています.")
        return True


if __name__ == "__main__":
    file1 = 'output/DFT.csv'
    file2 = 'output/FFT.csv'

    csv_compare(file1, file2)
