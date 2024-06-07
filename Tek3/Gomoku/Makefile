##
## EPITECH PROJECT, 2023
## B-AIA-500-MPL-5-1-gomoku-loic.tisseyre
## File description:
## Makefile
##

SRC	=	$(shell find src -name '*.py')
MAIN	=	$(shell find src -name 'main.py')
PYCACHE	=	$(shell find src -name '__pycache__')

TARGET	=	pbrain-gomoku-ai

$(TARGET):
	@echo "#!/bin/bash" > $(TARGET)
	@echo "python3 $(MAIN) \"\$$@\"" >> $(TARGET)
	@chmod +x $(TARGET)

exe:
	@pip install pyinstaller
	@pyinstaller $(SRC) --name $(TARGET).exe --onefile
	@cp dist/$(TARGET).exe $(TARGET).exe
	@echo "$(GREEN)$(TARGET)$(RESET) created"

clean:
	@rm -f -r dist build $(PYCACHE) *.spec
	@echo "$(YELLOW)Cleaned$(RESET)"

fclean: clean
	@rm -f $(TARGET)
	@rm -f $(TARGET).exe
	@echo "$(RED)$(TARGET)$(RESET) removed"

re: fclean all

all: $(TARGET)

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \033[0m