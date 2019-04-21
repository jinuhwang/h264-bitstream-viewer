dist/h264bitstream.js: src/h264bitstream-wrapper.cpp h264bitstream/.libs/libh264bitstream.so.0.0.0
	emcc \
		--bind \
		-O2  \
		-s ASSERTIONS=1 \
		-s EXTRA_EXPORTED_RUNTIME_METHODS='["setValue"]' \
		-Ih264bitstream/ \
		-o $@ \
		$^

h264bitstream/.libs/libh264bitstream.so.0.0.0:
	cd h264bitstream \
		&& emconfigure ./configure \
		&& emmake make CFLAGS=-DHAVE_SEI

.PHONY: build clean dist_static dist_clean deploy

dist_static: src/index.html src/index.js src/style.css
	cp -t dist/ $?

dist_clean:
	rm dist/*

build: dist_static dist/h264bitstream.js

clean:
	cd h264bitstream \
		&& make clean

deploy:
	git subtree push --prefix dist origin gh-pages
