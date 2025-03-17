def main():
    list_bin_dec = []
    with open("./formatter.txt", "r") as file:
        for i in file.readlines():
            try:
                bin_number = i.strip().replace(" ", "")
                list_bin_dec.append((int(bin_number, 2)))
            except:
                continue
    print(list_bin_dec)
    with open("./formatter_parsed.txt", "a") as file:
        file.write("----------- DEC -------------")
        file.write("\n")
        for i in list_bin_dec:
            file.write(f"{str(i)}\n")


if __name__ == "__main__":
    main()
