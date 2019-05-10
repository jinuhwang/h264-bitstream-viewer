<template>
  <div>
    <Table>
      <template v-for="(_, i) in payload.num_seis">
        <Row :key="`payloadType_${i}`">
          <Cell>sei[{{ i }}].payloadType</Cell>
          <Cell>
            {{ payload.seis.get(i).payloadType }}
            <i>
              ({{ payload.seis.get(i).payloadType | seiPayloadTypeDisplayed }})
            </i>
          </Cell>
        </Row>
        <Row :key="`payloadSize_${i}`">
          <Cell>sei[{{ i }}].payloadSize</Cell>
          <Cell>{{ payload.seis.get(i).payloadSize }}</Cell>
        </Row>
        <Row :key="`data_${i}`">
          <Cell>sei[{{ i }}].data</Cell>
          <Cell>
            <template v-for="(_, j) in payload.seis.get(i).payloadSize">
              {{ String.fromCharCode(payload.seis.get(i).data.get(j)) }}
            </template>
          </Cell>
        </Row>
      </template>
    </Table>
  </div>
</template>

<script>
import { Table, Row, Cell } from './Table';

export default {
  components: {
    Table,
    Row,
    Cell,
  },

  props: {
    payload: {
      type: Object,
      default: () => {},
    },
  },
};
</script>

<style module></style>
