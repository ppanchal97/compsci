import sys
import random
from pyfiglet import Figlet

figlet = Figlet()

def main():
    argc = len(sys.argv)
    # get fonts
    all_fonts = figlet.getFonts()

    if argc == 1:
        text = input("text: ")
        # select a random font
        random_font = str(random.choice(all_fonts))
        # output using that random font
        figlet.setFont(font=random_font)
        print(figlet.renderText(text))
    elif argc == 3:
        if sys.argv[1] in {'-f', '--font'}:
            # use specified font
            user_font= sys.argv[2]
            if user_font in all_fonts:
                text = input("text: ")
                figlet.setFont(font=user_font)
                # output using that font
                print(figlet.renderText(text))
            else:
                print("Invalid Usage")
                sys.exit(1)
        else:
            print("Invalid Usage")    
            sys.exit(1)
    else:
        print("Invalid Usage")
        sys.exit(1)

    # exit
    sys.exit(0)

main()