import csv
import random

def generate_random_numbers(N, min, max):
    return [round(random.uniform(min, max), 4) for _ in range(N)]

def write_to_csv(filename, data):
    with open(filename, 'w') as file:
        for number in data:
            file.write(str(number) + '\n')



if __name__ == "__main__":
    N = 2048  # 乱数の個数
    min = -10.0  # 最小値
    max = 10.0  # 最大値
    filename = "input/signal.csv"  # 出力ファイル名

    random_numbers = generate_random_numbers(N, min, max)
    write_to_csv(filename, random_numbers)
