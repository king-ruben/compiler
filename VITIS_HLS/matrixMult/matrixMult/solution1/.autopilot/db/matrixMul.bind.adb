<?xml version="1.0" encoding="UTF-8" standalone="yes" ?>
<!DOCTYPE boost_serialization>
<boost_serialization signature="serialization::archive" version="17">
<syndb class_id="0" tracking_level="0" version="0">
	<userIPLatency>-1</userIPLatency>
	<userIPName></userIPName>
	<cdfg class_id="1" tracking_level="1" version="0" object_id="_0">
		<name>matrixMul</name>
		<module_structure>Pipeline</module_structure>
		<ret_bitwidth>0</ret_bitwidth>
		<ports class_id="2" tracking_level="0" version="0">
			<count>0</count>
			<item_version>0</item_version>
		</ports>
		<nodes class_id="3" tracking_level="0" version="0">
			<count>1</count>
			<item_version>0</item_version>
			<item class_id="4" tracking_level="1" version="0" object_id="_1">
				<Value class_id="5" tracking_level="0" version="0">
					<Obj class_id="6" tracking_level="0" version="0">
						<type>0</type>
						<id>5</id>
						<name>_ln39</name>
						<fileName>maxMul.cpp</fileName>
						<fileDirectory>/home/rrm/COMPILER/VITIS_HLS/matrixMult</fileDirectory>
						<lineNumber>39</lineNumber>
						<contextFuncName>matrixMul</contextFuncName>
						<contextNormFuncName>matrixMul</contextNormFuncName>
						<inlineStackInfo class_id="7" tracking_level="0" version="0">
							<count>1</count>
							<item_version>0</item_version>
							<item class_id="8" tracking_level="0" version="0">
								<first>/home/rrm/COMPILER/VITIS_HLS/matrixMult</first>
								<second class_id="9" tracking_level="0" version="0">
									<count>1</count>
									<item_version>0</item_version>
									<item class_id="10" tracking_level="0" version="0">
										<first class_id="11" tracking_level="0" version="0">
											<first>maxMul.cpp</first>
											<second>matrixMul</second>
										</first>
										<second>39</second>
									</item>
								</second>
							</item>
						</inlineStackInfo>
						<originalName></originalName>
						<rtlName></rtlName>
						<control></control>
						<opType></opType>
						<implIndex></implIndex>
						<coreName></coreName>
						<isStorage>0</isStorage>
						<storageDepth>0</storageDepth>
						<coreId>1667592275</coreId>
						<rtlModuleName></rtlModuleName>
					</Obj>
					<bitwidth>0</bitwidth>
				</Value>
				<oprand_edges>
					<count>0</count>
					<item_version>0</item_version>
				</oprand_edges>
				<opcode>ret</opcode>
				<m_Display>0</m_Display>
				<m_isOnCriticalPath>0</m_isOnCriticalPath>
				<m_isLCDNode>0</m_isLCDNode>
				<m_isStartOfPath>0</m_isStartOfPath>
				<m_delay>0.00</m_delay>
				<m_topoIndex>1</m_topoIndex>
				<m_clusterGroupNumber>-1</m_clusterGroupNumber>
			</item>
		</nodes>
		<consts class_id="13" tracking_level="0" version="0">
			<count>0</count>
			<item_version>0</item_version>
		</consts>
		<blocks class_id="14" tracking_level="0" version="0">
			<count>1</count>
			<item_version>0</item_version>
			<item class_id="15" tracking_level="1" version="0" object_id="_2">
				<Obj>
					<type>3</type>
					<id>6</id>
					<name>matrixMul</name>
					<fileName></fileName>
					<fileDirectory></fileDirectory>
					<lineNumber>0</lineNumber>
					<contextFuncName></contextFuncName>
					<contextNormFuncName></contextNormFuncName>
					<inlineStackInfo>
						<count>0</count>
						<item_version>0</item_version>
					</inlineStackInfo>
					<originalName></originalName>
					<rtlName></rtlName>
					<control></control>
					<opType></opType>
					<implIndex></implIndex>
					<coreName></coreName>
					<isStorage>0</isStorage>
					<storageDepth>0</storageDepth>
					<coreId>4294967295</coreId>
					<rtlModuleName></rtlModuleName>
				</Obj>
				<node_objs>
					<count>1</count>
					<item_version>0</item_version>
					<item>5</item>
				</node_objs>
			</item>
		</blocks>
		<edges class_id="16" tracking_level="0" version="0">
			<count>0</count>
			<item_version>0</item_version>
		</edges>
	</cdfg>
	<cdfg_regions class_id="17" tracking_level="0" version="0">
		<count>1</count>
		<item_version>0</item_version>
		<item class_id="18" tracking_level="1" version="0" object_id="_3">
			<mId>1</mId>
			<mTag>matrixMul</mTag>
			<mNormTag>matrixMul</mNormTag>
			<mType>0</mType>
			<sub_regions>
				<count>0</count>
				<item_version>0</item_version>
			</sub_regions>
			<basic_blocks>
				<count>1</count>
				<item_version>0</item_version>
				<item>6</item>
			</basic_blocks>
			<mII>1</mII>
			<mDepth>1</mDepth>
			<mMinTripCount>-1</mMinTripCount>
			<mMaxTripCount>-1</mMaxTripCount>
			<mMinLatency>0</mMinLatency>
			<mMaxLatency>0</mMaxLatency>
			<mIsDfPipe>0</mIsDfPipe>
			<mDfPipe class_id="-1"></mDfPipe>
		</item>
	</cdfg_regions>
	<fsm class_id="20" tracking_level="1" version="0" object_id="_4">
		<states class_id="21" tracking_level="0" version="0">
			<count>1</count>
			<item_version>0</item_version>
			<item class_id="22" tracking_level="1" version="0" object_id="_5">
				<id>1</id>
				<operations class_id="23" tracking_level="0" version="0">
					<count>5</count>
					<item_version>0</item_version>
					<item class_id="24" tracking_level="1" version="0" object_id="_6">
						<id>1</id>
						<stage>1</stage>
						<latency>1</latency>
					</item>
					<item class_id_reference="24" object_id="_7">
						<id>2</id>
						<stage>1</stage>
						<latency>1</latency>
					</item>
					<item class_id_reference="24" object_id="_8">
						<id>3</id>
						<stage>1</stage>
						<latency>1</latency>
					</item>
					<item class_id_reference="24" object_id="_9">
						<id>4</id>
						<stage>1</stage>
						<latency>1</latency>
					</item>
					<item class_id_reference="24" object_id="_10">
						<id>5</id>
						<stage>1</stage>
						<latency>1</latency>
					</item>
				</operations>
			</item>
		</states>
		<transitions class_id="25" tracking_level="0" version="0">
			<count>0</count>
			<item_version>0</item_version>
		</transitions>
	</fsm>
	<res class_id="-1"></res>
	<node_label_latency class_id="27" tracking_level="0" version="0">
		<count>1</count>
		<item_version>0</item_version>
		<item class_id="28" tracking_level="0" version="0">
			<first>5</first>
			<second class_id="29" tracking_level="0" version="0">
				<first>0</first>
				<second>0</second>
			</second>
		</item>
	</node_label_latency>
	<bblk_ent_exit class_id="30" tracking_level="0" version="0">
		<count>1</count>
		<item_version>0</item_version>
		<item class_id="31" tracking_level="0" version="0">
			<first>6</first>
			<second class_id="32" tracking_level="0" version="0">
				<first>0</first>
				<second>0</second>
			</second>
		</item>
	</bblk_ent_exit>
	<regions class_id="33" tracking_level="0" version="0">
		<count>1</count>
		<item_version>0</item_version>
		<item class_id="34" tracking_level="1" version="0" object_id="_11">
			<region_name>matrixMul</region_name>
			<basic_blocks>
				<count>1</count>
				<item_version>0</item_version>
				<item>6</item>
			</basic_blocks>
			<nodes>
				<count>0</count>
				<item_version>0</item_version>
			</nodes>
			<anchor_node>-1</anchor_node>
			<region_type>8</region_type>
			<interval>1</interval>
			<pipe_depth>1</pipe_depth>
			<mDBIIViolationVec class_id="35" tracking_level="0" version="0">
				<count>0</count>
				<item_version>0</item_version>
			</mDBIIViolationVec>
		</item>
	</regions>
	<dp_fu_nodes class_id="36" tracking_level="0" version="0">
		<count>0</count>
		<item_version>0</item_version>
	</dp_fu_nodes>
	<dp_fu_nodes_expression class_id="37" tracking_level="0" version="0">
		<count>0</count>
		<item_version>0</item_version>
	</dp_fu_nodes_expression>
	<dp_fu_nodes_module>
		<count>0</count>
		<item_version>0</item_version>
	</dp_fu_nodes_module>
	<dp_fu_nodes_io>
		<count>0</count>
		<item_version>0</item_version>
	</dp_fu_nodes_io>
	<return_ports>
		<count>0</count>
		<item_version>0</item_version>
	</return_ports>
	<dp_mem_port_nodes class_id="38" tracking_level="0" version="0">
		<count>0</count>
		<item_version>0</item_version>
	</dp_mem_port_nodes>
	<dp_reg_nodes>
		<count>0</count>
		<item_version>0</item_version>
	</dp_reg_nodes>
	<dp_regname_nodes>
		<count>0</count>
		<item_version>0</item_version>
	</dp_regname_nodes>
	<dp_reg_phi>
		<count>0</count>
		<item_version>0</item_version>
	</dp_reg_phi>
	<dp_regname_phi>
		<count>0</count>
		<item_version>0</item_version>
	</dp_regname_phi>
	<dp_port_io_nodes class_id="39" tracking_level="0" version="0">
		<count>0</count>
		<item_version>0</item_version>
	</dp_port_io_nodes>
	<port2core>
		<count>0</count>
		<item_version>0</item_version>
	</port2core>
	<node2core>
		<count>0</count>
		<item_version>0</item_version>
	</node2core>
</syndb>
</boost_serialization>

