all:
	gcc *.c -o main

teste:
	./main < testes/entrada_1 > testes/out_1
	./main < testes/entrada_2 > testes/out_2
	./main < testes/entrada_3 > testes/out_3
	./main < testes/entrada_4 > testes/out_4
	./main < testes/entrada_5 > testes/out_5
	./main < testes/entrada_6 > testes/out_6

diff:
	diff testes/saida_1 testes/out_1
	diff testes/saida_2 testes/out_2
	#diff testes/saida_3 testes/out_3
	#diff testes/saida_4 testes/out_4
	diff testes/saida_5 testes/out_5
	diff testes/saida_6 testes/out_6