class Flaske:
    def __init__(self, volum):
        self.volum = volum
        self.fyllingsgrad = 0
        self.er_åpen = False
        
    def fyll(self):
        ...

    def tøm(self):
        ...

    def skrukork(self):
        self.er_åpen = not False

    def __str__(self):
        return f"Flaske, informasjon\nVolum: {self.volum}\nFyllingsgrad: {self.fyllingsgrad}\nEr den åpen: {self.er_åpen}"

        
def main():
    cola = Flaske(500)
    isklar = Flaske(460)

    cola.skrukork()
    print(cola)
    print(f"Cola status: {cola.er_åpen}\nIsklar status: {isklar.er_åpen}")
    

if __name__ == "__main__":
    main()