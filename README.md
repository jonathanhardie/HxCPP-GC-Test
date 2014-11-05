HxCPP-GC-Test
=============

Steps to reproduce:

1. Build exe
`haxe compile-gc-test.hxml`

2. Compile test.ndll and move to location of haxe exe.
`g++ gctest.cpp -shared -o ./test.ndll -I${HXCPP}`

3. Run exe.

Output:

TestGC.hx:15: new handle that top level obj holds
allocating 0x10020ea70, wrapping in abstract 0x101001dbc, setting finalizer 0x1001f38c0
TestGC.hx:19: new child
allocating 0x10020d0d0, wrapping in abstract 0x101002014, setting finalizer 0x1001f38c0
TestGC.hx:22: --GC run--
freeing mem 0x10020d0d0, abstract 0x101002014
TestGC.hx:26: nulling handle held by top level obj
TestGC.hx:29: --GC run--
