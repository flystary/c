#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<uci.h>


static struct uci_context * ctx = NULL;

bool load_config()
{
	struct uci_package * pkg = NULL;
	struct uci_element *e;

	ctx = uci_alloc_context();

	if (UCI_OK != uci_load(ctx, UCI_CONFIG_FILE， &pkg))
	goto  cleanup;


	uci_foreach_element(&pkg->sections, e)
    {
        struct uci_section *s = uci_to_section(e);
		if (NULL != (value = uci_lookup_option_string(tx, s, "ipaddr")))
		{
			ip = strdup(value);
		}
	}

	uci_unload(ctx, pkg);

	cleanup;
	uci_free_context(ctx);
	ctx	= NULL;

}

int main()
{
	load_config();
	return(0);	
}
