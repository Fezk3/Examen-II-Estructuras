from grafo import *


class Control:

    def __init__(self):
        self.grafito = Grafo()
        self.grafito.llena_grafo()

    def menu(self):

        opciones = ""

        for i, nodo in enumerate(self.grafito.nodos):
            opciones += ("\n" + str(i + 1) + " - " + nodo)

        while True:

            partida = ""
            destino = ""
            conti = ""

            while not partida.isdigit():
                partida = input(f"Digite un punto de partida:\n {opciones} \n")
                if not partida.isdigit():
                    print(f'\n**** Digito una opcion invalida ****\n')
                else:
                    if int(partida) > 7 or int(partida) < 1:
                        print(f'\n**** Digito una opcion invalida ****\n')
                        partida = ""

            while not destino.isdigit():
                destino = input(f"Digite un punto de destino:\n {opciones} \n")
                if not destino.isdigit():
                    print(f'\n**** Digito una opcion invalida ****\n')
                else:
                    if destino.isdigit() and int(destino) > 7 or int(destino) < 1:
                        print(f'\n**** Digito una opcion invalida ****\n')
                        destino = ""

            if partida == destino:
                print("El destino debe ser diferente a la partida!")
                input("Presione enter para continuar")

            else:
                camino = find_path(self.grafito.grafo, self.grafito.nodos[int(partida) - 1], self.grafito.nodos[int(destino) - 1])
                print(f"\nEl camino mas corto entre los nodos: {self.grafito.nodos[int(partida) - 1]} y {self.grafito.nodos[int(destino) - 1]} es:")
                print(f"->".join(camino.nodes))
                while not conti.isdigit():
                    conti = input("\nDesea calcular otra ruta?\n 1.Si\t2.No\n")
                    if not conti.isdigit():
                        if conti != "1" and conti != "2":
                            conti = ""
                            print(f'\n**** Digito una opcion invalida ****\n')
                if int(conti) == 1:
                    input("Presione enter para continuar\n\n")
                else:
                    print("Saliendo...")
                    break
