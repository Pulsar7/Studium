import os


def main() -> None:
    directory_path = os.getcwd()
    c_files = []
    for root, dirs, files in os.walk(directory_path):
        for file in files:
            if file.endswith(".c"):
                c_files.append(os.path.join(root, file))
    for file in c_files:
        os.system(f"gcc -c '{file}' -o '{file[:len(file)-2]}.o'")
    os.system(f"""gcc {' '.join([f"'{file[:len(file)-2]}.o'" for file in c_files])} -o main""")


if __name__ == '__main__':
    main()