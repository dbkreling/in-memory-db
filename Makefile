CODE_DIR = src

all: compile_database

compile_database:
	$(MAKE) -C $(CODE_DIR)
