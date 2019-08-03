__kernel void test(__global int *test)
{
    int id = get_global_id(0);
    test[id] += id;
}
