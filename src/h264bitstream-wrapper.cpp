#include <iostream>
#include <sstream>

#include <emscripten.h>
#include <emscripten/bind.h>

#include <h264_stream.h>

// using namespace emscripten;
using namespace std;

extern "C" {

// The following functions:
// - print_sps
// - print_slice_header
// - print_aud
// - print_nal
//
// Were copied and modified from the file:
//
// https://github.com/shi-yan/H264Naked/blob/master/H264NALListModel.cpp
//
// which is a part of open-source project
//
// https://github.com/shi-yan/H264Naked
//
// licensed under MIT License
//
// https://github.com/shi-yan/H264Naked/blob/master/LICENSE
//
// Which is preserved right below:
//
// The MIT License (MIT)
//
// Copyright (c) 2015 Shi Yan
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

void print_sps(stringstream &ts, sps_t* sps)
{
    ts << "======= SPS =======\n";
    ts << " profile_idc :" << sps->profile_idc <<"\n";
    ts << " constraint_set0_flag :"<< sps->constraint_set0_flag <<"\n";
    ts << " constraint_set1_flag :" << sps->constraint_set1_flag <<"\n";
    ts << " constraint_set2_flag :" << sps->constraint_set2_flag <<"\n";
    ts << " constraint_set3_flag :" << sps->constraint_set3_flag <<"\n";
    ts << " constraint_set4_flag :" << sps->constraint_set4_flag <<"\n";
    ts << " constraint_set5_flag :" << sps->constraint_set5_flag <<"\n";
    ts << " reserved_zero_2bits :" << sps->reserved_zero_2bits <<"\n";
    ts << " level_idc :" << sps->level_idc <<"\n";
    ts << " seq_parameter_set_id :" << sps->seq_parameter_set_id <<"\n";
    ts << " chroma_format_idc :" << sps->chroma_format_idc <<"\n";
    ts << " residual_colour_transform_flag :" << sps->residual_colour_transform_flag <<"\n";
    ts << " bit_depth_luma_minus8 :" << sps->bit_depth_luma_minus8 <<"\n";
    ts << " bit_depth_chroma_minus8 :" << sps->bit_depth_chroma_minus8 <<"\n";
    ts << " qpprime_y_zero_transform_bypass_flag :" << sps->qpprime_y_zero_transform_bypass_flag <<"\n";
    ts << " seq_scaling_matrix_present_flag :" << sps->seq_scaling_matrix_present_flag <<"\n";
    //  int seq_scaling_list_present_flag[8];
    //  void* ScalingList4x4[6];
    //  int UseDefaultScalingMatrix4x4Flag[6];
    //  void* ScalingList8x8[2];
    //  int UseDefaultScalingMatrix8x8Flag[2];
    ts << " log2_max_frame_num_minus4 :" << sps->log2_max_frame_num_minus4 <<"\n";
    ts << " pic_order_cnt_type :" << sps->pic_order_cnt_type <<"\n";
      ts << "   log2_max_pic_order_cnt_lsb_minus4 :" << sps->log2_max_pic_order_cnt_lsb_minus4 <<"\n";
      ts << "   delta_pic_order_always_zero_flag :" << sps->delta_pic_order_always_zero_flag <<"\n";
      ts << "   offset_for_non_ref_pic :" << sps->offset_for_non_ref_pic <<"\n";
      ts << "   offset_for_top_to_bottom_field :" << sps->offset_for_top_to_bottom_field <<"\n";
      ts << "   num_ref_frames_in_pic_order_cnt_cycle :" << sps->num_ref_frames_in_pic_order_cnt_cycle <<"\n";
    //  int offset_for_ref_frame[256];
    ts << " num_ref_frames :" << sps->num_ref_frames <<"\n";
    ts << " gaps_in_frame_num_value_allowed_flag :" << sps->gaps_in_frame_num_value_allowed_flag <<"\n";
    ts << " pic_width_in_mbs_minus1 :" << sps->pic_width_in_mbs_minus1 <<"\n";
    ts << " pic_height_in_map_units_minus1 :" << sps->pic_height_in_map_units_minus1 <<"\n";
    ts << " frame_mbs_only_flag :" << sps->frame_mbs_only_flag <<"\n";
    ts << " mb_adaptive_frame_field_flag :" << sps->mb_adaptive_frame_field_flag <<"\n";
    ts << " direct_8x8_inference_flag :" << sps->direct_8x8_inference_flag <<"\n";
    ts << " frame_cropping_flag :" << sps->frame_cropping_flag <<"\n";
    ts << "   frame_crop_left_offset :" << sps->frame_crop_left_offset <<"\n";
    ts << "   frame_crop_right_offset :" << sps->frame_crop_right_offset <<"\n";
    ts << "   frame_crop_top_offset :" << sps->frame_crop_top_offset <<"\n";
    ts << "   frame_crop_bottom_offset :" << sps->frame_crop_bottom_offset <<"\n";
    ts << " vui_parameters_present_flag :" << sps->vui_parameters_present_flag <<"\n";

    ts << "=== VUI ===\n";
    ts << " aspect_ratio_info_present_flag :" << sps->vui.aspect_ratio_info_present_flag <<"\n";
    ts << "   aspect_ratio_idc :" << sps->vui.aspect_ratio_idc <<"\n";
    ts << "     sar_width :" << sps->vui.sar_width <<"\n";
    ts << "     sar_height :" << sps->vui.sar_height <<"\n";
    ts << " overscan_info_present_flag :" << sps->vui.overscan_info_present_flag <<"\n";
    ts << "   overscan_appropriate_flag :" << sps->vui.overscan_appropriate_flag <<"\n";
    ts << " video_signal_type_present_flag :" << sps->vui.video_signal_type_present_flag <<"\n";
    ts << "   video_format :" << sps->vui.video_format <<"\n";
    ts << "   video_full_range_flag :" << sps->vui.video_full_range_flag <<"\n";
    ts << "   colour_description_present_flag :" << sps->vui.colour_description_present_flag <<"\n";
    ts << "     colour_primaries :" << sps->vui.colour_primaries <<"\n";
    ts << "   transfer_characteristics :" << sps->vui.transfer_characteristics <<"\n";
    ts << "   matrix_coefficients :" << sps->vui.matrix_coefficients <<"\n";
    ts << " chroma_loc_info_present_flag :" << sps->vui.chroma_loc_info_present_flag <<"\n";
    ts << "   chroma_sample_loc_type_top_field :" << sps->vui.chroma_sample_loc_type_top_field <<"\n";
    ts << "   chroma_sample_loc_type_bottom_field :" << sps->vui.chroma_sample_loc_type_bottom_field <<"\n";
    ts << " timing_info_present_flag :" << sps->vui.timing_info_present_flag <<"\n";
    ts << "   num_units_in_tick :" << sps->vui.num_units_in_tick <<"\n";
    ts << "   time_scale :" << sps->vui.time_scale <<"\n";
    ts << "   fixed_frame_rate_flag :" << sps->vui.fixed_frame_rate_flag <<"\n";
    ts << " nal_hrd_parameters_present_flag :" << sps->vui.nal_hrd_parameters_present_flag <<"\n";
    ts << " vcl_hrd_parameters_present_flag :" << sps->vui.vcl_hrd_parameters_present_flag <<"\n";
    ts << "   low_delay_hrd_flag :" << sps->vui.low_delay_hrd_flag <<"\n";
    ts << " pic_struct_present_flag :" << sps->vui.pic_struct_present_flag <<"\n";
    ts << " bitstream_restriction_flag :" << sps->vui.bitstream_restriction_flag <<"\n";
    ts << "   motion_vectors_over_pic_boundaries_flag :" << sps->vui.motion_vectors_over_pic_boundaries_flag <<"\n";
    ts << "   max_bytes_per_pic_denom :" << sps->vui.max_bytes_per_pic_denom <<"\n";
    ts << "   max_bits_per_mb_denom :" << sps->vui.max_bits_per_mb_denom <<"\n";
    ts << "   log2_max_mv_length_horizontal :" << sps->vui.log2_max_mv_length_horizontal <<"\n";
    ts << "   log2_max_mv_length_vertical :" << sps->vui.log2_max_mv_length_vertical <<"\n";
    ts << "   num_reorder_frames :" << sps->vui.num_reorder_frames <<"\n";
    ts << "   max_dec_frame_buffering :" << sps->vui.max_dec_frame_buffering <<"\n";

    ts << "=== HRD ===\n";
    ts << " cpb_cnt_minus1 :" << sps->hrd_nal.cpb_cnt_minus1 <<"\n";
    ts << " bit_rate_scale :" << sps->hrd_nal.bit_rate_scale <<"\n";
    ts << " cpb_size_scale :" << sps->hrd_nal.cpb_size_scale <<"\n";
    int SchedSelIdx;
    for( SchedSelIdx = 0; SchedSelIdx <= sps->hrd_nal.cpb_cnt_minus1; SchedSelIdx++ )
    {
        ts << "   bit_rate_value_minus1[" << SchedSelIdx <<"] :"<< sps->hrd_nal.bit_rate_value_minus1[SchedSelIdx] <<"\n"; // up to cpb_cnt_minus1, which is <= 31
        ts << "   cpb_size_value_minus1[" << SchedSelIdx << "] :"<< sps->hrd_nal.cpb_size_value_minus1[SchedSelIdx] <<"\n";
        ts << "   cbr_flag[" << SchedSelIdx <<"] :" << sps->hrd_nal.cbr_flag[SchedSelIdx] <<"\n";
    }
    ts << " initial_cpb_removal_delay_length_minus1 :" << sps->hrd_nal.initial_cpb_removal_delay_length_minus1 <<"\n";
    ts << " cpb_removal_delay_length_minus1 :" << sps->hrd_nal.cpb_removal_delay_length_minus1 <<"\n";
    ts << " dpb_output_delay_length_minus1 :" << sps->hrd_nal.dpb_output_delay_length_minus1 <<"\n";
    ts << " time_offset_length :" << sps->hrd_nal.time_offset_length <<"\n";
}

void print_slice_header(stringstream &ts, slice_header_t* sh)
{
    ts << "======= Slice Header =======\n";
    ts << " first_mb_in_slice :" << sh->first_mb_in_slice <<"\n";
    const char* slice_type_name;
    switch(sh->slice_type)
    {
    case SH_SLICE_TYPE_P :       slice_type_name = "P slice"; break;
    case SH_SLICE_TYPE_B :       slice_type_name = "B slice"; break;
    case SH_SLICE_TYPE_I :       slice_type_name = "I slice"; break;
    case SH_SLICE_TYPE_SP :      slice_type_name = "SP slice"; break;
    case SH_SLICE_TYPE_SI :      slice_type_name = "SI slice"; break;
    case SH_SLICE_TYPE_P_ONLY :  slice_type_name = "P slice only"; break;
    case SH_SLICE_TYPE_B_ONLY :  slice_type_name = "B slice only"; break;
    case SH_SLICE_TYPE_I_ONLY :  slice_type_name = "I slice only"; break;
    case SH_SLICE_TYPE_SP_ONLY : slice_type_name = "SP slice only"; break;
    case SH_SLICE_TYPE_SI_ONLY : slice_type_name = "SI slice only"; break;
    default :                    slice_type_name = "Unknown"; break;
    }
    ts << " slice_type :" << sh->slice_type << " " << slice_type_name << "\n";

    ts << " pic_parameter_set_id :" << sh->pic_parameter_set_id <<"\n";
    ts <<" frame_num :" << sh->frame_num << "\n";
    ts << " field_pic_flag :" << sh->field_pic_flag <<"\n";
    ts << " bottom_field_flag :" << sh->bottom_field_flag <<"\n";
    ts << " idr_pic_id :" << sh->idr_pic_id <<"\n";
    ts << " pic_order_cnt_lsb :" << sh->pic_order_cnt_lsb <<"\n";
    ts << " delta_pic_order_cnt_bottom :" << sh->delta_pic_order_cnt_bottom <<"\n";
    // int delta_pic_order_cnt[ 2 ];
    ts << " redundant_pic_cnt :" << sh->redundant_pic_cnt <<"\n";
    ts << " direct_spatial_mv_pred_flag :" << sh->direct_spatial_mv_pred_flag <<"\n";
    ts << " num_ref_idx_active_override_flag :" << sh->num_ref_idx_active_override_flag <<"\n";
    ts << " num_ref_idx_l0_active_minus1 :" << sh->num_ref_idx_l0_active_minus1 <<"\n";
    ts << " num_ref_idx_l1_active_minus1 :" << sh->num_ref_idx_l1_active_minus1 <<"\n";
    ts << " cabac_init_idc :" << sh->cabac_init_idc <<"\n";
    ts << " slice_qp_delta :" << sh->slice_qp_delta <<"\n";
    ts << " sp_for_switch_flag :" << sh->sp_for_switch_flag <<"\n";
    ts << " slice_qs_delta :" << sh->slice_qs_delta <<"\n";
    ts << " disable_deblocking_filter_idc :" << sh->disable_deblocking_filter_idc <<"\n";
    ts << " slice_alpha_c0_offset_div2 :" << sh->slice_alpha_c0_offset_div2 <<"\n";
    ts << " slice_beta_offset_div2 :" << sh->slice_beta_offset_div2 <<"\n";
    ts << " slice_group_change_cycle :" << sh->slice_group_change_cycle <<"\n";

    ts << "=== Prediction Weight Table ===\n";
    ts << " luma_log2_weight_denom :" << sh->pwt.luma_log2_weight_denom <<"\n";
    ts << " chroma_log2_weight_denom :"<< sh->pwt.chroma_log2_weight_denom <<"\n";
    ts << " luma_weight_l0_flag :"<< sh->pwt.luma_weight_l0_flag <<"\n";
    // int luma_weight_l0[64];
    // int luma_offset_l0[64];
    ts << " chroma_weight_l0_flag :"<< sh->pwt.chroma_weight_l0_flag <<"\n";
    // int chroma_weight_l0[64][2];
    // int chroma_offset_l0[64][2];
    ts << " luma_weight_l1_flag :"<< sh->pwt.luma_weight_l1_flag <<"\n";
    // int luma_weight_l1[64];
    // int luma_offset_l1[64];
    ts << " chroma_weight_l1_flag :"<< sh->pwt.chroma_weight_l1_flag <<"\n";
    // int chroma_weight_l1[64][2];
    // int chroma_offset_l1[64][2];

    ts << "=== Ref Pic List Reordering ===\n";
    ts << " ref_pic_list_reordering_flag_l0 :" << sh->rplr.ref_pic_list_reordering_flag_l0 <<"\n";
    ts << " ref_pic_list_reordering_flag_l1 :" << sh->rplr.ref_pic_list_reordering_flag_l1 <<"\n";
        // int reordering_of_pic_nums_idc;
        // int abs_diff_pic_num_minus1;
        // int long_term_pic_num;

    ts << "=== Decoded Ref Pic Marking ===\n";
    ts << " no_output_of_prior_pics_flag :" << sh->drpm.no_output_of_prior_pics_flag <<"\n";
    ts << " long_term_reference_flag :" << sh->drpm.long_term_reference_flag <<"\n";
    ts << " adaptive_ref_pic_marking_mode_flag :" << sh->drpm.adaptive_ref_pic_marking_mode_flag <<"\n";
        // int memory_management_control_operation;
        // int difference_of_pic_nums_minus1;
        // int long_term_pic_num;
        // int long_term_frame_idx;
        // int max_long_term_frame_idx_plus1;

}

void print_aud(stringstream &ts, aud_t* aud)
{
    ts << "======= Access Unit Delimiter =======\n";
    const char* primary_pic_type_name;
    switch (aud->primary_pic_type)
    {
    case AUD_PRIMARY_PIC_TYPE_I :       primary_pic_type_name = "I"; break;
    case AUD_PRIMARY_PIC_TYPE_IP :      primary_pic_type_name = "I, P"; break;
    case AUD_PRIMARY_PIC_TYPE_IPB :     primary_pic_type_name = "I, P, B"; break;
    case AUD_PRIMARY_PIC_TYPE_SI :      primary_pic_type_name = "SI"; break;
    case AUD_PRIMARY_PIC_TYPE_SISP :    primary_pic_type_name = "SI, SP"; break;
    case AUD_PRIMARY_PIC_TYPE_ISI :     primary_pic_type_name = "I, SI"; break;
    case AUD_PRIMARY_PIC_TYPE_ISIPSP :  primary_pic_type_name = "I, SI, P, SP"; break;
    case AUD_PRIMARY_PIC_TYPE_ISIPSPB : primary_pic_type_name = "I, SI, P, SP, B"; break;
    default : primary_pic_type_name = "Unknown"; break;
    }
    ts << " primary_pic_type :" << aud->primary_pic_type << primary_pic_type_name <<"\n";
}

void print_nal(stringstream &ts, h264_stream_t* h, nal_t* nal)
{
    if( nal->nal_unit_type == NAL_UNIT_TYPE_CODED_SLICE_NON_IDR) { print_slice_header(ts, h->sh); }
    else if( nal->nal_unit_type == NAL_UNIT_TYPE_CODED_SLICE_IDR) { print_slice_header(ts, h->sh); }
    else if( nal->nal_unit_type == NAL_UNIT_TYPE_SPS) { print_sps(ts, h->sps); }
    else if( nal->nal_unit_type == NAL_UNIT_TYPE_AUD) { print_aud(ts, h->aud); }
}

struct PayloadSEIItem {
  int payloadType;
  int payloadSize;
  std::vector<uint8_t> data;
};

struct PayloadSEI {
  int num_seis;
  std::vector<PayloadSEIItem> seis;
};

struct PayloadPPS {
  int pic_parameter_set_id;
  int seq_parameter_set_id;
  int entropy_coding_mode_flag;
  int pic_order_present_flag;
  int num_slice_groups_minus1;
  int slice_group_map_type;
  std::vector<int> run_length_minus1;
  std::vector<int> top_left;
  std::vector<int> bottom_right;
  int slice_group_change_direction_flag;
  int slice_group_change_rate_minus1;
  int pic_size_in_map_units_minus1;
  std::vector<int> slice_group_id;
  int num_ref_idx_l0_active_minus1;
  int num_ref_idx_l1_active_minus1;
  int weighted_pred_flag;
  int weighted_bipred_idc;
  int pic_init_qp_minus26;
  int pic_init_qs_minus26;
  int chroma_qp_index_offset;
  int deblocking_filter_control_present_flag;
  int constrained_intra_pred_flag;
  int redundant_pic_cnt_present_flag;
  int transform_8x8_mode_flag;
  int pic_scaling_matrix_present_flag;
  int second_chroma_qp_index_offset;
};

struct Reader {
  Reader() {}

  string readToString(uintptr_t input, int size) {
    const int32_t* data = reinterpret_cast<int32_t*>(input);

    uint8_t* buf = new uint8_t[size];

    for (int i = 0; i < size; i += 1) {
      buf[i] = (uint8_t) (data[i] & 0xff);
    }

    h264_stream_t* h = h264_new();

    int ret = read_nal_unit(h, buf, size);

    // cout << "ret = " << ret << endl;

    stringstream ss;

    print_nal(ss, h, h->nal);

    // cout << ss.str() << endl;

    h264_free(h);

    delete [] buf;

    return ss.str();
  }

  PayloadSEI readSEI(uintptr_t input, int size) {
    const int32_t* data = reinterpret_cast<int32_t*>(input);

    uint8_t* buf = new uint8_t[size];

    for (int i = 0; i < size; i += 1) {
      buf[i] = (uint8_t) (data[i] & 0xff);
    }

    h264_stream_t* h = h264_new();

    int ret = read_nal_unit(h, buf, size);

    PayloadSEI payload;

    sei_t** seis = h->seis;
    int num_seis = h->num_seis;

    payload.num_seis = num_seis;

    for (int i = 0; i < num_seis; i++) {
      sei_t* sei = seis[i];

      PayloadSEIItem seiItem;
      seiItem.payloadType = sei->payloadType;
      seiItem.payloadSize = sei->payloadSize;

      seiItem.data.resize(sei->payloadSize);

      // seiItem.data.assign(*sei->data, sei->payloadSize);
      for (int i = 0; i < sei->payloadSize; i += 1) {
        seiItem.data.at(i) = sei->data[i];
      }

      payload.seis.push_back(seiItem);
    }

    h264_free(h);

    delete [] buf;

    return payload;
  }

  PayloadPPS readPPS(uintptr_t input, int size) {
    const int32_t* data = reinterpret_cast<int32_t*>(input);

    uint8_t* buf = new uint8_t[size];

    for (int i = 0; i < size; i += 1) {
      buf[i] = (uint8_t) (data[i] & 0xff);
    }

    h264_stream_t* h = h264_new();

    int ret = read_nal_unit(h, buf, size);

    PayloadPPS payload;

    pps_t* pps = h->pps;

    payload.pic_parameter_set_id = pps->pic_parameter_set_id;
    payload.seq_parameter_set_id = pps->seq_parameter_set_id;
    payload.entropy_coding_mode_flag = pps->entropy_coding_mode_flag;
    payload.pic_order_present_flag = pps->pic_order_present_flag;
    payload.num_slice_groups_minus1 = pps->num_slice_groups_minus1;
    payload.slice_group_map_type = pps->slice_group_map_type;
    payload.run_length_minus1.assign(*pps->run_length_minus1, 8);
    payload.top_left.assign(*pps->top_left, 8);
    payload.bottom_right.assign(*pps->bottom_right, 8);
    payload.slice_group_change_direction_flag = pps->slice_group_change_direction_flag;
    payload.slice_group_change_rate_minus1 = pps->slice_group_change_rate_minus1;
    payload.pic_size_in_map_units_minus1 = pps->pic_size_in_map_units_minus1;
    payload.slice_group_id.assign(*pps->slice_group_id, 8);
    payload.num_ref_idx_l0_active_minus1 = pps->num_ref_idx_l0_active_minus1;
    payload.num_ref_idx_l1_active_minus1 = pps->num_ref_idx_l1_active_minus1;
    payload.weighted_pred_flag = pps->weighted_pred_flag;
    payload.weighted_bipred_idc = pps->weighted_bipred_idc;
    payload.pic_init_qp_minus26 = pps->pic_init_qp_minus26;
    payload.pic_init_qs_minus26 = pps->pic_init_qs_minus26;
    payload.chroma_qp_index_offset = pps->chroma_qp_index_offset;
    payload.deblocking_filter_control_present_flag = pps->deblocking_filter_control_present_flag;
    payload.constrained_intra_pred_flag = pps->constrained_intra_pred_flag;
    payload.redundant_pic_cnt_present_flag = pps->redundant_pic_cnt_present_flag;
    payload.transform_8x8_mode_flag = pps->transform_8x8_mode_flag;
    payload.pic_scaling_matrix_present_flag = pps->pic_scaling_matrix_present_flag;
    payload.second_chroma_qp_index_offset = pps->second_chroma_qp_index_offset;

    h264_free(h);

    delete [] buf;

    return payload;
  }
};

EMSCRIPTEN_BINDINGS(H264Bitstream) {

  emscripten::register_vector<int>("vector<int>");
  emscripten::register_vector<uint8_t>("vector<uint8_t>");
  emscripten::register_vector<PayloadSEIItem>("vector<PayloadSEIItem>");

  emscripten::class_<Reader>("Reader")
    .constructor<>()
    .function("readToString", &Reader::readToString)
    .function("readPPS", &Reader::readPPS)
    .function("readSEI", &Reader::readSEI)
    ;

  emscripten::value_object<PayloadSEI>("PayloadSEI")
    .field("num_seis", &PayloadSEI::num_seis)
    .field("seis", &PayloadSEI::seis)
    ;

  emscripten::value_object<PayloadSEIItem>("PayloadSEIItem")
    .field("payloadType", &PayloadSEIItem::payloadType)
    .field("payloadSize", &PayloadSEIItem::payloadSize)
    .field("data", &PayloadSEIItem::data)
    ;


  emscripten::value_object<PayloadPPS>("PayloadPPS")
    .field("pic_parameter_set_id", &PayloadPPS::pic_parameter_set_id)
    .field("seq_parameter_set_id", &PayloadPPS::seq_parameter_set_id)
    .field("entropy_coding_mode_flag", &PayloadPPS::entropy_coding_mode_flag)
    .field("pic_order_present_flag", &PayloadPPS::pic_order_present_flag)
    .field("num_slice_groups_minus1", &PayloadPPS::num_slice_groups_minus1)
    .field("slice_group_map_type", &PayloadPPS::slice_group_map_type)
    .field("run_length_minus1", &PayloadPPS::run_length_minus1)
    .field("top_left", &PayloadPPS::top_left)
    .field("bottom_right", &PayloadPPS::bottom_right)
    .field("slice_group_change_direction_flag", &PayloadPPS::slice_group_change_direction_flag)
    .field("slice_group_change_rate_minus1", &PayloadPPS::slice_group_change_rate_minus1)
    .field("pic_size_in_map_units_minus1", &PayloadPPS::pic_size_in_map_units_minus1)
    .field("slice_group_id", &PayloadPPS::slice_group_id)
    .field("num_ref_idx_l0_active_minus1", &PayloadPPS::num_ref_idx_l0_active_minus1)
    .field("num_ref_idx_l1_active_minus1", &PayloadPPS::num_ref_idx_l1_active_minus1)
    .field("weighted_pred_flag", &PayloadPPS::weighted_pred_flag)
    .field("weighted_bipred_idc", &PayloadPPS::weighted_bipred_idc)
    .field("pic_init_qp_minus26", &PayloadPPS::pic_init_qp_minus26)
    .field("pic_init_qs_minus26", &PayloadPPS::pic_init_qs_minus26)
    .field("chroma_qp_index_offset", &PayloadPPS::chroma_qp_index_offset)
    .field("deblocking_filter_control_present_flag", &PayloadPPS::deblocking_filter_control_present_flag)
    .field("constrained_intra_pred_flag", &PayloadPPS::constrained_intra_pred_flag)
    .field("redundant_pic_cnt_present_flag", &PayloadPPS::redundant_pic_cnt_present_flag)
    .field("transform_8x8_mode_flag", &PayloadPPS::transform_8x8_mode_flag)
    .field("pic_scaling_matrix_present_flag", &PayloadPPS::pic_scaling_matrix_present_flag)
    .field("second_chroma_qp_index_offset", &PayloadPPS::second_chroma_qp_index_offset)
    ;

}

}
