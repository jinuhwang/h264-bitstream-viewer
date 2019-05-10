import { NALU_TYPES, SEI_PAYLOAD_TYPES } from '../constants';

const nalHelper = {
  naluTypeDisplayed(naluType) {
    switch (naluType) {
      case NALU_TYPES.UNSPECIFIED:
        return 'Unspecified';
      case NALU_TYPES.CODED_SLICE_NON_IDR:
        return 'Coded slice of a non-IDR picture';
      case NALU_TYPES.CODED_SLICE_DATA_PARTITION_A:
        return 'Coded slice data partition A';
      case NALU_TYPES.CODED_SLICE_DATA_PARTITION_B:
        return 'Coded slice data partition B';
      case NALU_TYPES.CODED_SLICE_DATA_PARTITION_C:
        return 'Coded slice data partition C';
      case NALU_TYPES.CODED_SLICE_IDR:
        return 'Coded slice of an IDR picture';
      case NALU_TYPES.SEI:
        return 'Supplemental enchancement information (SEI)';
      case NALU_TYPES.SPS:
        return 'Sequence parameter set';
      case NALU_TYPES.PPS:
        return 'Picture parameter set';
      case NALU_TYPES.AUD:
        return 'Access unit delimiter';
      case NALU_TYPES.END_OF_SEQUENCE:
        return 'End of sequence';
      case NALU_TYPES.END_OF_STREAM:
        return 'End of stream';
      case NALU_TYPES.FILLER:
        return 'Filler data';
      case NALU_TYPES.SPS_EXT:
        return 'Sequence parameter set extension';
      case NALU_TYPES.PREFIX_NAL:
        return 'Prefix NAL unit';
      case NALU_TYPES.SUBSET_SPS:
        return 'Subset sequence parameter set';
      case NALU_TYPES.DPS:
        return 'Depth parameter set';
      case NALU_TYPES.CODED_SLICE_AUX:
        return 'Coded slice of an auxiliary coded picture without partitioning';
      case NALU_TYPES.CODED_SLICE_SVC_EXTENSION:
        return 'Coded slice of SVC extension';
      default:
        return 'Unknown';
    }
  },

  seiPayloadTypeDisplayed(seiPayloadType) {
    switch (seiPayloadType) {
      case SEI_PAYLOAD_TYPES.BUFFERING_PERIOD:
        return 'Buffering period';
      case SEI_PAYLOAD_TYPES.PIC_TIMING:
        return 'Pic timing';
      case SEI_PAYLOAD_TYPES.PAN_SCAN_RECT:
        return 'Pan scan rect';
      case SEI_PAYLOAD_TYPES.FILLER_PAYLOAD:
        return 'Filler payload';
      case SEI_PAYLOAD_TYPES.USER_DATA_REGISTERED_ITU_T_T35:
        return 'User data registered ITU-T T35';
      case SEI_PAYLOAD_TYPES.USER_DATA_UNREGISTERED:
        return 'User data unregistered';
      case SEI_PAYLOAD_TYPES.RECOVERY_POINT:
        return 'Recovery point';
      case SEI_PAYLOAD_TYPES.DEC_REF_PIC_MARKING_REPETITION:
        return 'Dec ref pic marking repetition';
      case SEI_PAYLOAD_TYPES.SPARE_PIC:
        return 'Spare pic';
      case SEI_PAYLOAD_TYPES.SCENE_INFO:
        return 'Scene info';
      case SEI_PAYLOAD_TYPES.SUB_SEQ_INFO:
        return 'Sub seq info';
      case SEI_PAYLOAD_TYPES.SUB_SEQ_LAYER_CHARACTERISTICS:
        return 'Sub seq layer characteristics';
      case SEI_PAYLOAD_TYPES.SUB_SEQ_CHARACTERISTICS:
        return 'Sub seq characteristics';
      case SEI_PAYLOAD_TYPES.FULL_FRAME_FREEZE:
        return 'Full frame freeze';
      case SEI_PAYLOAD_TYPES.FULL_FRAME_FREEZE_RELEASE:
        return 'Full frame freeze release';
      case SEI_PAYLOAD_TYPES.FULL_FRAME_SNAPSHOT:
        return 'Full frame snapshot';
      case SEI_PAYLOAD_TYPES.PROGRESSIVE_REFINEMENT_SEGMENT_START:
        return 'Progressive refinement segment start';
      case SEI_PAYLOAD_TYPES.PROGRESSIVE_REFINEMENT_SEGMENT_END:
        return 'Progressive refinement segment end';
      case SEI_PAYLOAD_TYPES.MOTION_CONSTRAINED_SLICE_GROUP_SET:
        return 'Motion constrained slice group set';
      case SEI_PAYLOAD_TYPES.FILM_GRAIN_CHARACTERISTICS:
        return 'Film grain characteristics';
      case SEI_PAYLOAD_TYPES.DEBLOCKING_FILTER_DISPLAY_PREFERENCE:
        return 'Deblocking filter display preference';
      case SEI_PAYLOAD_TYPES.STEREO_VIDEO_INFO:
        return 'Stereo video info';
      case SEI_PAYLOAD_TYPES.SCALABILITY_INFO:
        return 'Scalability info';
      default:
        return 'Unknown';
    }
  },
};

export default nalHelper;
