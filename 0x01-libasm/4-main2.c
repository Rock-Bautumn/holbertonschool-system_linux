/* Description: `asm_strstr(s1, s2)`, `s1` being a very long string and `s2` a word present in `s1` */

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1	"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ullamcorper velit sed ullamcorper morbi tincidunt ornare. Vitae semper quis lectus nulla at volutpat. Lacus vestibulum sed arcu non odio euismod lacinia at quis. Vitae ultricies leo integer malesuada nunc vel risus commodo viverra. Mattis nunc sed blandit libero volutpat sed. Aliquet bibendum enim facilisis gravida neque convallis a cras semper. Auctor neque vitae tempus quam pellentesque nec nam aliquam sem. Adipiscing elit duis tristique sollicitudin nibh sit amet commodo. Orci porta non pulvinar neque laoreet suspendisse interdum. Et ligula ullamcorper malesuada proin libero nunc consequat. Tellus cras adipiscing enim eu turpis egestas pretium. Consequat id porta nibh venenatis cras sed felis eget. Enim praesent elementum facilisis leo vel fringilla est ullamcorper eget. Imperdiet massa tincidunt nunc pulvinar sapien et. Magna ac placerat vestibulum lectus mauris ultrices eros in. Sed turpis tincidunt id aliquet risus. Turpis massa tincidunt dui ut ornare lectus sit amet est. Congue eu consequat ac felis donec. Augue ut lectus arcu bibendum.\n\
Varius vel pharetra vel turpis. Lorem ipsum dolor sit amet consectetur adipiscing elit. Arcu non sodales neque sodales ut. Facilisis gravida neque convallis a. Orci ac auctor augue mauris augue neque gravida in. Fringilla ut morbi tincidunt augue interdum. Adipiscing bibendum est ultricies integer quis auctor elit sed. Et pharetra pharetra massa massa. Dui id ornare arcu odio ut. Ut placerat orci nulla pellentesque.\n\
Felis imperdiet proin fermentum leo vel orci porta non. Porta non pulvinar neque laoreet suspendisse interdum consectetur. Consectetur lorem donec massa sapien faucibus et molestie ac. Commodo odio aenean sed adipiscing diam donec adipiscing. Metus dictum at tempor commodo ullamcorper. Volutpat est velit egestas dui id ornare arcu. Pellentesque eu tincidunt tortor aliquam nulla facilisi. Nunc consequat interdum varius sit amet mattis vulputate. Dignissim enim sit amet venenatis urna cursus eget. Morbi leo urna molestie at elementum eu. Et magnis dis parturient montes nascetur ridiculus. Nunc sed velit dignissim sodales ut eu sem integer. Ut porttitor leo a diam sollicitudin tempor. Sit amet consectetur adipiscing elit pellentesque habitant. Lacus vel facilisis volutpat est velit egestas dui. Accumsan in nisl nisi scelerisque eu ultrices vitae auctor. Purus ut faucibus pulvinar elementum integer enim neque. Mattis nunc sed blandit libero. Aliquam id diam maecenas ultricies mi eget. Eget dolor morbi non arcu risus quis varius quam quisque.\n\
Est sit amet facilisis magna etiam tempor orci eu. Faucibus a pellentesque sit amet porttitor. Nec feugiat in fermentum posuere urna nec tincidunt praesent. Feugiat scelerisque varius morbi enim. Ut ornare lectus sit amet est placerat in egestas. Pretium fusce id velit ut tortor pretium viverra suspendisse. Egestas integer eget aliquet nibh praesent tristique magna sit. Phasellus egestas tellus rutrum tellus. Magna fringilla urna porttitor rhoncus dolor. Dolor morbi non arcu risus quis varius. Malesuada bibendum arcu vitae elementum curabitur vitae nunc sed.\n\
Tincidunt praesent semper feugiat nibh sed pulvinar proin gravida hendrerit. Urna nunc id cursus metus aliquam. Ultrices in iaculis nunc sed augue lacus viverra. Eleifend donec pretium vulputate sapien nec sagittis aliquam. Aliquam id diam maecenas ultricies mi eget mauris. Egestas congue quisque egestas diam. Eu non diam phasellus vestibulum lorem. Sodales ut etiam sit amet nisl purus in. Sed libero enim sed faucibus. Quam lacus suspendisse faucibus interdum posuere lorem ipsum dolor. Non tellus orci ac auctor augue mauris augue neque gravida."
#define S2	"praesent"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	assert(strstr(S1, S2) == asm_strstr(S1, S2));

	printf("All good!\n");
	return (EXIT_SUCCESS);
}
