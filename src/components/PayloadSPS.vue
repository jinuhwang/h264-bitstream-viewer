<template>
  <div>
    <Table>
      <Row>
        <Cell>profile_idc</Cell>
        <Cell>{{ payload.profile_idc }}</Cell>
      </Row>
      <Row>
        <Cell>constraint_set0_flag</Cell>
        <Cell>{{ payload.constraint_set0_flag }}</Cell>
      </Row>
      <Row>
        <Cell>constraint_set1_flag</Cell>
        <Cell>{{ payload.constraint_set1_flag }}</Cell>
      </Row>
      <Row>
        <Cell>constraint_set2_flag</Cell>
        <Cell>{{ payload.constraint_set2_flag }}</Cell>
      </Row>
      <Row>
        <Cell>constraint_set3_flag</Cell>
        <Cell>{{ payload.constraint_set3_flag }}</Cell>
      </Row>
      <Row>
        <Cell>constraint_set4_flag</Cell>
        <Cell>{{ payload.constraint_set4_flag }}</Cell>
      </Row>
      <Row>
        <Cell>constraint_set5_flag</Cell>
        <Cell>{{ payload.constraint_set5_flag }}</Cell>
      </Row>
      <Row>
        <Cell>reserved_zero_2bits</Cell>
        <Cell>{{ payload.reserved_zero_2bits }}</Cell>
      </Row>
      <Row>
        <Cell>level_idc</Cell>
        <Cell>{{ payload.level_idc }}</Cell>
      </Row>
      <Row>
        <Cell>seq_parameter_set_id</Cell>
        <Cell>{{ payload.seq_parameter_set_id }}</Cell>
      </Row>

      <template
        v-if="
          payload.profile_idc === 100 ||
            payload.profile_idc === 110 ||
            payload.profile_idc === 122 ||
            payload.profile_idc === 244 ||
            payload.profile_idc === 44 ||
            payload.profile_idc === 83 ||
            payload.profile_idc === 86 ||
            payload.profile_idc === 118 ||
            payload.profile_idc === 128 ||
            payload.profile_idc === 138 ||
            payload.profile_idc === 139 ||
            payload.profile_idc === 134
        "
      >
        <Row>
          <Cell>chroma_format_idc</Cell>
          <Cell>{{ payload.chroma_format_idc }}</Cell>
        </Row>
        <Row v-if="payload.chroma_format_idc === 3">
          <Cell>residual_colour_transform_flag</Cell>
          <Cell>{{ payload.residual_colour_transform_flag }}</Cell>
        </Row>
        <Row>
          <Cell>bit_depth_luma_minus8</Cell>
          <Cell>{{ payload.bit_depth_luma_minus8 }}</Cell>
        </Row>
        <Row>
          <Cell>bit_depth_chroma_minus8</Cell>
          <Cell>{{ payload.bit_depth_chroma_minus8 }}</Cell>
        </Row>
        <Row>
          <Cell>qpprime_y_zero_transform_bypass_flag</Cell>
          <Cell>{{ payload.qpprime_y_zero_transform_bypass_flag }}</Cell>
        </Row>
        <Row>
          <Cell>seq_scaling_matrix_present_flag</Cell>
          <Cell>{{ payload.seq_scaling_matrix_present_flag }}</Cell>
        </Row>
        <template v-if="payload.seq_scaling_matrix_present_flag">
          <!-- TODO: scaling list -->
          <Row :class="$style.warn">
            <Cell colspan="2">TODO</Cell>
          </Row>
        </template>
      </template>

      <Row>
        <Cell>log2_max_frame_num_minus4</Cell>
        <Cell>{{ payload.log2_max_frame_num_minus4 }}</Cell>
      </Row>

      <Row>
        <Cell>pic_order_cnt_type</Cell>
        <Cell>{{ payload.pic_order_cnt_type }}</Cell>
      </Row>
      <template v-if="payload.pic_order_cnt_type === 0">
        <Row>
          <Cell>log2_max_pic_order_cnt_lsb_minus4</Cell>
          <Cell>{{ payload.log2_max_pic_order_cnt_lsb_minus4 }}</Cell>
        </Row>
      </template>
      <template v-if="payload.pic_order_cnt_type === 1">
        <Row>
          <Cell>delta_pic_order_always_zero_flag</Cell>
          <Cell>{{ payload.delta_pic_order_always_zero_flag }}</Cell>
        </Row>
        <Row>
          <Cell>offset_for_non_ref_pic</Cell>
          <Cell>{{ payload.offset_for_non_ref_pic }}</Cell>
        </Row>
        <Row>
          <Cell>offset_for_top_to_bottom_field</Cell>
          <Cell>{{ payload.offset_for_top_to_bottom_field }}</Cell>
        </Row>
        <Row>
          <Cell>num_ref_frames_in_pic_order_cnt_cycle</Cell>
          <Cell>{{ payload.num_ref_frames_in_pic_order_cnt_cycle }}</Cell>
        </Row>
        <!-- TODO: offset_for_ref_frame -->
        <Row :class="$style.warn">
          <Cell colspan="2">TODO</Cell>
        </Row>
      </template>

      <Row>
        <Cell>num_ref_frames</Cell>
        <Cell>{{ payload.num_ref_frames }}</Cell>
      </Row>
      <Row>
        <Cell>gaps_in_frame_num_value_allowed_flag</Cell>
        <Cell>{{ payload.gaps_in_frame_num_value_allowed_flag }}</Cell>
      </Row>
      <Row>
        <Cell>pic_width_in_mbs_minus1</Cell>
        <Cell>{{ payload.pic_width_in_mbs_minus1 }}</Cell>
      </Row>
      <Row>
        <Cell>pic_height_in_map_units_minus1</Cell>
        <Cell>{{ payload.pic_height_in_map_units_minus1 }}</Cell>
      </Row>

      <Row>
        <Cell>frame_mbs_only_flag</Cell>
        <Cell>{{ payload.frame_mbs_only_flag }}</Cell>
      </Row>
      <template v-if="!payload.frame_mbs_only_flag">
        <Row>
          <Cell>mb_adaptive_frame_field_flag</Cell>
          <Cell>{{ payload.mb_adaptive_frame_field_flag }}</Cell>
        </Row>
      </template>

      <Row>
        <Cell>direct_8x8_inference_flag</Cell>
        <Cell>{{ payload.direct_8x8_inference_flag }}</Cell>
      </Row>

      <Row>
        <Cell>frame_cropping_flag</Cell>
        <Cell>{{ payload.frame_cropping_flag }}</Cell>
      </Row>
      <template v-if="payload.frame_cropping_flag">
        <Row>
          <Cell>frame_crop_left_offset</Cell>
          <Cell>{{ payload.frame_crop_left_offset }}</Cell>
        </Row>
        <Row>
          <Cell>frame_crop_right_offset</Cell>
          <Cell>{{ payload.frame_crop_right_offset }}</Cell>
        </Row>
        <Row>
          <Cell>frame_crop_top_offset</Cell>
          <Cell>{{ payload.frame_crop_top_offset }}</Cell>
        </Row>
        <Row>
          <Cell>frame_crop_bottom_offset</Cell>
          <Cell>{{ payload.frame_crop_bottom_offset }}</Cell>
        </Row>
      </template>

      <Row>
        <Cell>vui_parameters_present_flag</Cell>
        <Cell>{{ payload.vui_parameters_present_flag }}</Cell>
      </Row>
      <template v-if="payload.vui_parameters_present_flag">
        <Row>
          <Cell>vui.aspect_ratio_info_present_flag</Cell>
          <Cell>{{ payload.vui.aspect_ratio_info_present_flag }}</Cell>
        </Row>

        <template v-if="payload.vui.aspect_ratio_info_present_flag">
          <Row>
            <Cell>vui.aspect_ratio_idc</Cell>
            <Cell>{{ payload.vui.aspect_ratio_idc }}</Cell>
          </Row>
          <template
            v-if="payload.vui.aspect_ratio_idc === $options.SAR.EXTENDED"
          >
            <Row>
              <Cell>vui.sar_width</Cell>
              <Cell>{{ payload.vui.sar_width }}</Cell>
            </Row>
            <Row>
              <Cell>vui.sar_height</Cell>
              <Cell>{{ payload.vui.sar_height }}</Cell>
            </Row>
          </template>
        </template>

        <Row>
          <Cell>vui.overscan_info_present_flag</Cell>
          <Cell>{{ payload.vui.overscan_info_present_flag }}</Cell>
        </Row>
        <template v-if="payload.vui.overscan_info_present_flag">
          <Row>
            <Cell>vui.overscan_appropriate_flag</Cell>
            <Cell>{{ payload.vui.overscan_appropriate_flag }}</Cell>
          </Row>
        </template>

        <Row>
          <Cell>vui.video_signal_type_present_flag</Cell>
          <Cell>{{ payload.vui.video_signal_type_present_flag }}</Cell>
        </Row>
        <template v-if="payload.vui.video_signal_type_present_flag">
          <Row>
            <Cell>vui.video_format</Cell>
            <Cell>{{ payload.vui.video_format }}</Cell>
          </Row>
          <Row>
            <Cell>vui.video_full_range_flag</Cell>
            <Cell>{{ payload.vui.video_full_range_flag }}</Cell>
          </Row>
          <Row>
            <Cell>vui.colour_description_present_flag</Cell>
            <Cell>{{ payload.vui.colour_description_present_flag }}</Cell>
          </Row>
          <template v-if="payload.vui.colour_description_present_flag">
            <Row>
              <Cell>vui.colour_primaries</Cell>
              <Cell>{{ payload.vui.colour_primaries }}</Cell>
            </Row>
            <Row>
              <Cell>vui.transfer_characteristics</Cell>
              <Cell>{{ payload.vui.transfer_characteristics }}</Cell>
            </Row>
            <Row>
              <Cell>vui.matrix_coefficients</Cell>
              <Cell>{{ payload.vui.matrix_coefficients }}</Cell>
            </Row>
          </template>
        </template>

        <Row>
          <Cell>vui.chroma_loc_info_present_flag</Cell>
          <Cell>{{ payload.vui.chroma_loc_info_present_flag }}</Cell>
        </Row>
        <template v-if="payload.vui.chroma_loc_info_present_flag">
          <Row>
            <Cell>vui.chroma_sample_loc_type_top_field</Cell>
            <Cell>{{ payload.vui.chroma_sample_loc_type_top_field }}</Cell>
          </Row>
          <Row>
            <Cell>vui.chroma_sample_loc_type_bottom_field</Cell>
            <Cell>{{ payload.vui.chroma_sample_loc_type_bottom_field }}</Cell>
          </Row>
        </template>

        <Row>
          <Cell>vui.timing_info_present_flag</Cell>
          <Cell>{{ payload.vui.timing_info_present_flag }}</Cell>
        </Row>
        <template v-if="payload.vui.timing_info_present_flag">
          <Row>
            <Cell>vui.num_units_in_tick</Cell>
            <Cell>{{ payload.vui.num_units_in_tick }}</Cell>
          </Row>
          <Row>
            <Cell>vui.time_scale</Cell>
            <Cell>{{ payload.vui.time_scale }}</Cell>
          </Row>
          <Row>
            <Cell>vui.fixed_frame_rate_flag</Cell>
            <Cell>{{ payload.vui.fixed_frame_rate_flag }}</Cell>
          </Row>
        </template>

        <Row>
          <Cell>vui.nal_hrd_parameters_present_flag</Cell>
          <Cell>{{ payload.vui.nal_hrd_parameters_present_flag }}</Cell>
        </Row>
        <template v-if="payload.vui.nal_hrd_parameters_present_flag">
          <!-- TODO: read_debug_hrd_parameters(&sps->hrd_nal, b); -->
          <Row :class="$style.warn">
            <Cell colspan="2">TODO</Cell>
          </Row>
        </template>

        <Row>
          <Cell>vui.vcl_hrd_parameters_present_flag</Cell>
          <Cell>{{ payload.vui.vcl_hrd_parameters_present_flag }}</Cell>
        </Row>
        <template v-if="payload.vui.vcl_hrd_parameters_present_flag">
          <!-- TODO: read_debug_hrd_parameters(&sps->hrd_vcl, b); -->
          <Row :class="$style.warn">
            <Cell colspan="2">TODO</Cell>
          </Row>
        </template>

        <template
          v-if="
            payload.vui.nal_hrd_parameters_present_flag ||
              payload.vui.vcl_hrd_parameters_present_flag
          "
        >
          <Row>
            <Cell>vui.low_delay_hrd_flag</Cell>
            <Cell>{{ payload.vui.low_delay_hrd_flag }}</Cell>
          </Row>
        </template>

        <Row>
          <Cell>vui.pic_struct_present_flag</Cell>
          <Cell>{{ payload.vui.pic_struct_present_flag }}</Cell>
        </Row>

        <Row>
          <Cell>vui.bitstream_restriction_flag</Cell>
          <Cell>{{ payload.vui.bitstream_restriction_flag }}</Cell>
        </Row>
        <template v-if="payload.vui.bitstream_restriction_flag">
          <Row>
            <Cell>vui.motion_vectors_over_pic_boundaries_flag</Cell>
            <Cell>{{
              payload.vui.motion_vectors_over_pic_boundaries_flag
            }}</Cell>
          </Row>
          <Row>
            <Cell>vui.max_bytes_per_pic_denom</Cell>
            <Cell>{{ payload.vui.max_bytes_per_pic_denom }}</Cell>
          </Row>
          <Row>
            <Cell>vui.max_bits_per_mb_denom</Cell>
            <Cell>{{ payload.vui.max_bits_per_mb_denom }}</Cell>
          </Row>
          <Row>
            <Cell>vui.log2_max_mv_length_horizontal</Cell>
            <Cell>{{ payload.vui.log2_max_mv_length_horizontal }}</Cell>
          </Row>
          <Row>
            <Cell>vui.log2_max_mv_length_vertical</Cell>
            <Cell>{{ payload.vui.log2_max_mv_length_vertical }}</Cell>
          </Row>
          <Row>
            <Cell>vui.num_reorder_frames</Cell>
            <Cell>{{ payload.vui.num_reorder_frames }}</Cell>
          </Row>
          <!-- TODO: for out.h264 sps->vui.max_dec_frame_buffering: 4 -->
          <Row :class="$style.warn">
            <Cell>vui.max_dec_frame_buffering</Cell>
            <Cell>{{ payload.vui.max_dec_frame_buffering }}</Cell>
          </Row>
        </template>
      </template>
    </Table>
  </div>
</template>

<script>
import { Table, Row, Cell } from './Table';

import { SAR } from '../constants';

export default {
  components: {
    Table,
    Row,
    Cell,
  },

  SAR,

  props: {
    payload: {
      type: Object,
      default: () => {},
    },
  },
};
</script>

<style module>
.warn {
  background: #fbd7d4;
}
</style>
