#### SEI

- Optimize passing data as something else instead of vector of ints
- Add support for `SEI_TYPE_SCALABILITY_INFO = 24` content
- Test on different videos to check most of SEI types

#### PPS

- In h264bitstream there are different bitstream reader functions: bs_read_u1, bs_read_ue, bs_read_se, etc. Sometimes values don't match with h264bitstream, maybe because of them.
- `intlog2` in `slice_group_id loop`
- `have_more_data` condition
- `second_chroma_qp_index_offset`: for file out.h264 the value in h264bitstream output is negative "-2", but I have positive "2"
- RBSP trailing bits?
