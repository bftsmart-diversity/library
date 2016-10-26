package bftsmartclient

import "bftsmart"
import "fmt"

func CreateServiceProxy(id int, clspath string) int {
	bftsmart.SetClasspath(clspath)
	bftsmart.CarregarJvm()
	return bftsmart.CreateServiceProxy(id)
}

func InvokeOrdered(command []byte) []byte {
	var rst []byte
	fmt.Printf("%v", command);
	rst = bftsmart.InvokeOrdered(command)
	fmt.Printf("%v", rst);
	return rst
}

func InvokeUnordered(command []byte) []byte {
        var rst []byte
        fmt.Printf("%v", command);
        rst = bftsmart.InvokeOrdered(command)
        fmt.Printf("%v", rst);
        return rst

}

func FinalizarJvm() {
	bftsmart.FinalizarJvm()
}
