//
//  httpparser.h
//  etape3NE302
//
//  Created by Nolan on 05/05/2020.
//  Copyright © 2020 Nolan. All rights reserved.
//

#ifndef httpparser_h
#define httpparser_h

#include <stdio.h>

void *httpgetRootTree();

typedef struct node {
        int level;
        char *name;
        char *value ;
        int len;
        int explored;
        struct node *link;
        } Lnode ;

#endif /* httpparser_h */
