import csv
import random
import sys

def generate_random_numbers(N, min, max):
    return [round(random.uniform(min, max), 4) for _ in range(N)]

def write_to_csv(filename, data):
    with open(filename, 'w') as file:
        for number in data:
            file.write(str(number) + '\n')

if __name__ == "__main__":
    if len(sys.argv) != 2:
        sys.exit(1)

    power = int(sys.argv[1])  # 2のべき乗
    N = 2**power  # 乱数の個数
    min = -10.0  # 最小値
    max = 10.0  # 最大値
    filename = f"input/signal-{sys.argv[1]}.csv"  # 出力ファイル名

    random_numbers = generate_random_numbers(N, min, max)
    write_to_csv(filename, random_numbers)
    print(f"{N} done")
