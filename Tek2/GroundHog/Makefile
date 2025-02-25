PYTHON = python3
SRC = groundhog.py
OUT = groundhog

all: $(OUT)

$(OUT): $(SRC)
	@cp $(SRC) $(OUT)
	@chmod +x $(OUT)
	@echo "Groundhog compiled!"

clean:
	@rm -f $(OUT)
	@echo "Groundhog cleaned!"

fclean: clean

re: fclean all
