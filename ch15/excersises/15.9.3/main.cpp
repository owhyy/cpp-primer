#include "Query_versions.h"
#include "TextQuery.h"

int main() { Query q = Query("fiery") & Query("bird") | Query("wind"); }
