# push_swap — Notas personales (chguerre)

## ¿Qué hace el proyecto?

`push_swap` recibe números enteros como argumentos y imprime en stdout la secuencia mínima de operaciones para ordenarlos de menor a mayor en el stack A.

## Estructuras de datos

```
t_node {
    next     → siguiente nodo
    prev     → nodo anterior
    contain  → valor original del número
    index    → índice binario asignado por parsing_index (0 = el menor)
}

t_manager {
    head_a / tail_a  → inicio y fin del stack A
    head_b / tail_b  → inicio y fin del stack B
    qty_in_a         → cantidad de elementos en A
    qty_in_b         → cantidad de elementos en B
}
```

## Las 11 operaciones

| Operación | Qué hace |
|-----------|----------|
| `sa` | Intercambia los 2 primeros de A |
| `sb` | Intercambia los 2 primeros de B |
| `ss` | sa + sb al mismo tiempo |
| `pa` | Mueve el tope de B al tope de A |
| `pb` | Mueve el tope de A al tope de B |
| `ra` | Rota A hacia arriba (el primero pasa al fondo) |
| `rb` | Rota B hacia arriba |
| `rr` | ra + rb al mismo tiempo |
| `rra` | Rota A hacia abajo (el último sube al tope) |
| `rrb` | Rota B hacia abajo |
| `rrr` | rra + rrb al mismo tiempo |

## Algoritmo de ordenamiento

### Casos pequeños

- **1 número**: nada que hacer
- **2 números**: si head > tail → sa
- **3 números**: función dedicada con 6 casos, máximo 2 operaciones

### Radix sort (4+ números)

**Paso 1 — Indexar:** `parsing_index` asigna a cada nodo un índice binario:
- El número más pequeño recibe index = 0
- El más grande recibe index = n-1

**Paso 2 — Ordenar bit a bit:**
```
para cada bit (desde el bit 0 hasta el más significativo):
    para cada elemento en A:
        si el bit actual del index es 0 → pb (va a B)
        si el bit actual del index es 1 → ra (se queda en A, rota al fondo)
    mientras B no esté vacío → pa (devuelve todo a A)
```

**¿Por qué funciona?** Después de procesar todos los bits, los números están ordenados por su índice, que ya representaba el orden correcto.

## Flujo del main

```
1. parsing_args    → construye la lista enlazada + valida input + asigna índices
2. is_sorted       → si ya está ordenado, no hace nada
3. switch qty_in_a:
   - 1   → nada
   - 2   → sa si head > tail
   - 3   → sort_three_numbers
   - 4+  → radix_sort
4. free_all_stacks → libera memoria
```

## Errores que detecta

- Caracteres no numéricos (`"abc"`, `"12a3"`)
- Overflow de entero (fuera del rango INT_MIN / INT_MAX)
- Duplicados (`"3 3"`, `"-1 -001"`)
- Strings vacíos o solo espacios

## Rendimiento

| Tamaño | Operaciones | Puntuación |
|--------|-------------|------------|
| 100 números | ~1300 | 2/5 |
| 500 números | ~7800 | 3/5 |

## Bugs que encontré durante el desarrollo

- **Aliasing en swap**: guardar `first` y `second` antes de modificar cualquier puntero
- **Comparar punteros en vez de valores**: `head_a > tail_a` compara direcciones, no números → usar `->contain`
- **Array ya ordenado**: radix_sort emite operaciones incluso si no es necesario → agregar `is_sorted` antes de llamar al sort

## Autor

chguerre — 42 Lausanne
