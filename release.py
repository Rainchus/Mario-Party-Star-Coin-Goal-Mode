import os

def collect_sections(start_dir='.'):
    header = (
        "XXXX - star count to win in hex\n"
        "YYYY - coin count to win in hex\n"
        "to turn one of these off, set the value to 0000\n"
        "turning both off will default to 5 stars to win\n\n"
    )

    combined_text = [header]

    for root, dirs, files in os.walk(start_dir):
        if 'code.txt' in files:
            path = os.path.join(root, 'code.txt')
            with open(path, 'r', encoding='utf-8') as f:
                lines = f.readlines()
                for i, line in enumerate(lines):
                    if 'Star/Coin Goal Mode' in line:
                        combined_text.extend(lines[i:])
                        combined_text.append('\n')  # separation between entries
                        break

    return ''.join(combined_text)

if __name__ == '__main__':
    result = collect_sections()
    print(result)
