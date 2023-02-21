def count_lines(file_path):
    try:
        file = open(file_path, 'r')
    except IOError:
        print(f"Error opening file {file_path}")
    else:
        try:
            line_count = len(file.readlines())
            return line_count
        except IOError:
            print(f"Error reading file {file_path}")
        finally:
            file.close()


def main():
    print(count_lines("./lalaland.txt"))


main()
