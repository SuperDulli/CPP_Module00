CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

NAME	= dream_job
CLASSES	= Account.cpp
HEADERS	= $(patsubst %.cpp,%.hpp,$(CLASSES))
SRCS	= tests.cpp $(CLASSES)
OBJDIR	= obj
OBJS	= $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCS))

MYLOG	= mylog.log
INTRALOG= intralog.log

all: $(NAME)

clean:
	rm -rf $(OBJDIR)
	rm -f $(MYLOG)
	rm -f $(INTRALOG)
	rm -f $(MYLOG).notimestamp
	rm -f $(INTRALOG).notimestamp

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

show:
	@echo SRCS=$(SRCS)
	@echo OBJS=$(OBJS)

debug: fclean
debug: CFLAGS := $(CFLAGS) -g
debug: all

compare: $(MYLOG).notimestamp $(INTRALOG).notimestamp
	diff $^

$(NAME): $(OBJS) $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)

$(MYLOG): $(NAME)
	./$(NAME) > $(MYLOG)

%.notimestamp: %
	cut -d ' ' -f 2 $^ > $@

$(INTRALOG):
	curl https://projects.intra.42.fr/uploads/document/document/9239/19920104_091532.log > $(INTRALOG)

.PHONY: all clean fclean re show debug
