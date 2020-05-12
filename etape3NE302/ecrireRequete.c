#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  FILE * fic = NULL;
  char *req = "CONNECT / HTTP/1.1\r\nHost:  127.0.0.1:8080\r\nUser-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:76.0) Gecko/20100101 Firefox/76.0\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\nAccept-Language: fr,fr-FR;q=0.8,en-US;q=0.5,en;q=0.3\r\nAccept-Encoding: gzip, deflate\r\nTransfer-Encoding: gzip, chunked\r\nUpgrade-Insecure-Requests: 1\r\nCache-Control: max-age=0\r\n\r\n";
  if((fic = fopen("requete.txt", "w")) == NULL)
  {
    perror("Erreur d'ouverture du fichier\n");
    exit(0);
  }
  fprintf(fic,"%s",req);
  fclose(fic);
  return 0;
}
