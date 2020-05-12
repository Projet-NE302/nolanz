
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "httpparser.h"
#include "api.h"

int methodCheck(){
  _Token *root, *r, *s, *e, *t;
  int check = 1;
  root=getRootTree();
  r=searchTree(root,"method");
  s=searchTree(root,"message_body");
  e=searchTree(root,"transfer_encoding");
  t=searchTree(root,"content_length");

  Lnode *node, *nodes, *nodet, *nodee;
  int size = 0;
  node=(Lnode*)r->node;
  if(s) nodes=(Lnode*)s->node;
  if(t) nodet=(Lnode*)t->node;

  if(e && s) {
    while(e->next) e=e->next;
    nodee=(Lnode*)e->node;
    if(nodee->value!=NULL)if(!strcmp(nodee->value,"chunked")) check = -3; // Conformity of transfer_encoding value.
  }

  if(!(strcmp(node->value,"GET")) && !(strcmp(node->value,"HEAD")) && !(strcmp(node->value,"POST"))) check = -1; // Conformity of method value.

  if(s && t){
    while(nodes->value[size] != '\r') size++;
    if(size != atoi(nodet->value)) check = -2; // Conformity size of message_body compared to Content length value.
  }

  if(check==-1){
    printf("Method non-compliant.\n");
    return check;
  }
  if(check==-2){
    printf("Content-length non-compliant.\n");
    return check;
  }
  if(check==-3){
    printf("Transfer-encoding non-compliant.\n");
    return check;
  }
  if(check==1){
    printf("[Method & Message-body CHECK] : OK.\n");
    return check;
  }
}
