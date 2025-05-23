#!/bin/bash

# Compilar o código
gcc -o erro_acumulado erro_acumulado.c -lm

# Arquivo de saída
output="resultados_erros.csv"
echo "tipo,n,erro_real,erro_estimado" > $output

# Valores de n
valores_n=(10 100 1000 10000 100000 1000000 10000000)

# Tipos de representação
tipos=("float" "double" "longdouble")

# Valor de x
x=0.11

# Executar testes
for tipo in "${tipos[@]}"; do
  for n in "${valores_n[@]}"; do
    # Executa o programa e captura a saída
    resultado=$(./erro_acumulado $n $x $tipo)

    # Extrai os erros da saída
    erro_real=$(echo "$resultado" | grep "Erro relativo real" | awk '{print $5}')
    erro_estimado=$(echo "$resultado" | grep "Erro relativo estimado" | awk '{print $5}')

    # Escreve no CSV
    echo "$tipo,$n,$erro_real,$erro_estimado" >> $output
    echo "Executado: $tipo, n=$n"
  done
done

echo "Resultados salvos em $output"
