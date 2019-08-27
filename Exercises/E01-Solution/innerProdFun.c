 /*
  innerProdFun.c
  */

 float innerProdFun(float a[], float b[], int n) {
    float product = 0.0;
    
    for (int i = 0; i < n; i++) {
       product += a[i] * b[i];
    }
    return product;
 }
