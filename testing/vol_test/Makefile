OBJS=test.o ../../geo.o 
EXE=test
HEAD=../../geo.h ../../interp_1d.h ../../const.h
all: $(EXE)

# This rule uses the automatic variables, '$^' and '$@'
$(EXE): $(OBJS)
	g++ $^ -lgsl -lgslcblas -o $@

# This is a 'static pattern rule'
$(OBJS): %.o : %.cc $(HEAD)
	g++ -c $< -o $@

.PHONY: clean spotless

clean:
	\rm -f $(OBJS)

spotless:
	\rm -f $(OBJS) $(EXE)
