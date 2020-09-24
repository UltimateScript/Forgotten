
#ifndef FOGPARSERMAKER_HXX
#define FOGPARSERMAKER_HXX





class FogParserMaker : public FogParserBase, public FogScopeEnums {
	typedef FogParserBase Super;
	typedef FogParserMaker This;
	TYPEDECL_SINGLE(This, Super)
	
protected:
	FogParserMaker(FogLexerTower& aLexer, FogToken& firstToken, const char *aTitle, int aDepth)
			: Super(aLexer, firstToken, aTitle, aDepth) {}
			
	void make(const FogToken *aToken) {
		garbage_add(aToken);
	}
	
	CxxExpression *make_abstract_array_expression(CxxExpression *sizeExpr);
	CxxExpression *make_abstract_function_expression(CxxParenthesised *aparenthesis);
	CxxBaseSpecifier *make_access_base_specifier(CxxBaseSpecifier *baseSpecifier, CxxAccessSpecifier *accessSpecifier);
	CxxDeclSpecifierId *make_access_specifier_id(CxxAccessSpecifier *aName);
	CxxDeclaration *make_accessibility_specifier(CxxAccessSpecifier *accessSpecifier);
	CxxExpression *make_add_expression(CxxExpression *leftExpr, CxxExpression *rightExpr);
	CxxExpression *make_and_expression(CxxExpression *leftExpr, CxxExpression *rightExpr);
	CxxExpression *make_array_expression(CxxExpression *anExpr, CxxExpression *indexExpr);
	CxxExpression *make_arrow_expression(CxxExpression *anExpr, CxxName *aName);
	CxxExpression *make_arrow_star_expression(CxxExpression *anExpr, CxxExpression *memberExpr);
	CxxDeclaration *make_asm_definition(CxxStrings *aString);
	CxxExpression *make_assignment_expression(CxxExpression *leftExpr, CxxToken *assOp, CxxExpression *rightExpr);
	CxxBaseSpecifier *make_base_specifier(CxxName *aName);
	CxxBaseSpecifiers *make_base_specifiers(CxxBaseSpecifiers *aList, CxxBaseSpecifier *anElement);
	CxxExpression *make_bit_field_expression(CxxExpression *nameExpr, CxxExpression *sizeExpr);
	CxxStatement *make_break_statement();
	CxxName *make_built_in_id(CxxBuiltInId *aName);
	CxxName *make_built_in_id_id(CxxBuiltInId *aName);
	CxxBuiltInId *make_built_in_ids(CxxBuiltInId *anExpr, CxxBuiltInId *anElement);
	CxxName *make_built_in_name(CxxName *aName, CxxBuiltInId *anElement);
	CxxExpression *make_call_expression(CxxExpression *anExpr, CxxParenthesised *aParenthesis);
	CxxStatement *make_case_statement(CxxExpression *anExpr, CxxStatement *aStmt);
	CxxExpression *make_cast_expression(CxxExpression *aCast, CxxExpression *anExpr);
	CxxExpression *make_character_literal_expression(CxxCharacterLiteral *aLiteral);
	CxxName *make_class_members(CxxClass *aClass, CxxMemberDeclarations *memberDeclarations);
	CxxClass *make_class_specifier_id(CxxClassKey *classKey, CxxName *aName, CxxBaseSpecifiers *baseSpecifiers);
	CxxSimpleTypeParameter *make_class_type_parameter(CxxName *aName);
	CxxStatement *make_compound_statement(CxxStatements *statementList);
	CxxExpression *make_complement_expression(CxxExpression *anExpr);
	CxxCondition *make_condition(CxxParameters *aList);
	CxxExpression *make_conditional_expression(CxxExpression *testExpr, CxxExpression *trueExpr, CxxExpression *falseExpr);
	CxxExpression *make_const_cast_expression(CxxExpression *aType, CxxExpression *anExpr) ;
	CxxStatement *make_continue_statement();
	CxxName *make_conversion_function_id(CxxExpression *typeId);
	CxxExpression *make_ctor_definition(CxxExpressions *anExpr, CxxFunctionBody *functionBody);
	CxxExpression *make_ctor_expression(CxxExpression *anExpr);
	CxxFunctionBody *make_ctor_function_block(CxxFunctionBody *functionBody, CxxMemInitializers *ctorList);
	CxxDeclSpecifierId *make_cv_decl_specifier(CxxCvQualifiers *cvQualifiers);
	CxxPointerDeclarator *make_cv_declarator(CxxPointerDeclarator *aDeclarator, CxxCvQualifiers *cvQualifiers);
	CxxCvQualifiers *make_cv_qualifiers(CxxCvQualifiers *aList, CxxCvQualifiers *anElement);
	CxxDeclaration *make_decl_specifier_declaration(CxxDeclaration *aDeclaration, CxxDeclSpecifierId *declSpecifier);
	CxxExpression *make_decl_specifier_expression(CxxExpression *anExpr, CxxDeclSpecifierId *declSpecifier);
	CxxName *make_decl_specifier_name(CxxName *aName, CxxDeclSpecifierId *declSpecifier);
	CxxParameter *make_decl_specifier_parameter(CxxParameter *aName, CxxDeclSpecifierId *declSpecifier);
	CxxTokens *make_decl_specifier_tree_arguments(CxxTokens *treeArguments, CxxDeclSpecifierId *aName);
	CxxDeclSpecifierId *make_decl_specifiers(CxxDeclSpecifierId *aList, CxxDeclSpecifierId *anElement);
	CxxDeclarations *make_declarations(CxxDeclarations *aList, CxxDeclaration *anElement);
	CxxStatement *make_declaration_statement(CxxDeclaration *aDecl);
	CxxStatement *make_default_statement(CxxStatement *aStmt);
	CxxDeleteExpression *make_delete_expression(CxxExpression *anExpr);
	CxxDeclaration *make_derived_clause(CxxExpression *derivedPredicate, CxxDeclaration *aDeclaration);
	CxxName *make_destructor_id(CxxName *aName);
	CxxExpression *make_divide_expression(CxxExpression *leftExpr, CxxExpression *rightExpr);
	CxxStatement *make_do_while_statement(CxxStatement *aStmt, CxxExpression *testExpr);
	CxxExpression *make_dot_expression(CxxExpression *anExpr, CxxName *aName);
	CxxExpression *make_dot_star_expression(CxxExpression *anExpr, CxxExpression *memberExpr);
	CxxExpression *make_dynamic_cast_expression(CxxExpression *aType, CxxExpression *anExpr);
	CxxName *make_elaborated_type_specifier(CxxClassKey *classKey, CxxName *aName);
	CxxParameter *make_ellipsis_expression();
	CxxName *make_enum_specifier_id(CxxName *aName, CxxEnumerators *aList);
	CxxEnumerator *make_enumerator(CxxName *aName, CxxExpression *anExpr);
	CxxEnumerators *make_enumerators(CxxEnumerators *aList, CxxEnumerator *anElement);
	CxxName *make_epsilon();
	CxxExpression *make_equal_expression(CxxExpression *leftExpr, CxxExpression *rightExpr);
	CxxExceptionDeclaration *make_exception_declaration(CxxParameter *aParameter);
	CxxExceptionSpecification *make_exception_specification(CxxExpressions *typeIds);
	CxxExpression *make_exclusive_or_expression(CxxExpression *leftExpr, CxxExpression *rightExpr);
	CxxDeclaration *make_explicit_specialization(CxxDeclaration *aDeclaration);
	CxxDeclaration *make_export_all_declaration(CxxFileId *fileId);
	CxxDeclaration *make_export_implementation_declaration(CxxFileId *fileId);
	CxxDeclaration *make_export_interface_declaration(CxxFileId *fileId);
	CxxDeclaration *make_export_noimplementation_declaration();
	CxxDeclaration *make_export_utility_declaration(CxxUtility *aUtility);
	CxxExpression *make_expression(CxxExpressions *aList);
	CxxParameter *make_expression_parameter(CxxExpression *anExpr);
	CxxExpressions *make_expressions(CxxExpressions *aList, CxxExpression *anElement);
	CxxExpression *make_false_expression();
	CxxFileId *make_file_id(CxxFileName *fileName);
	CxxFileId *make_file_id_implementation(CxxName *aName);
	CxxFileId *make_file_id_interface(CxxName *aName);
	CxxFileIds *make_file_ids(CxxFileIds *aList, CxxFileId *anElement);
	CxxFileName *make_file_name(CxxExpression *aString);
	CxxFileName *make_file_name_guard(CxxFileName *fileName, CxxExpression *aString);
	CxxFileName *make_file_name_implementation(CxxFileName *fileName);
	CxxFileName *make_file_name_interface(CxxFileName *fileName);
	CxxFileName *make_file_name_noguard(CxxFileName *fileName);
	CxxFileName *make_file_name_path(CxxFileName *fileName, CxxExpression *aString);
	CxxFileName *make_file_name_prefix(CxxFileName *fileName, CxxExpression *aString);
	CxxFileName *make_file_name_suffix(CxxFileName *fileName, CxxExpression *aString);
	CxxFileName *make_file_name_template(CxxFileName *fileName);
	CxxFileName *make_file_name_utility(CxxFileName *fileName, CxxUtility *aUtility);
	CxxDeclaration *make_filespace_declaration(CxxName *aName);
	CxxName *make_filespace_specifier(CxxFileName *fileName, CxxDeclarations *aDeclaration);
	CxxExpression *make_floating_literal_expression(CxxFloatingLiteral *aLiteral);
	CxxStatement *make_for_statement(CxxExpression *initExpr, CxxCondition *testExpr, CxxExpression *stepExpr, CxxStatement *aStmt);
	CxxFunctionBody *make_function_block(CxxStatement *aStatement);
	CxxExpression *make_function_definition(CxxExpression *anExpr, CxxFunctionBody *functionBody);
	CxxDeclarator *make_global_declarator(CxxIsTemplate isTemplate, CxxDeclarator *aDeclarator);
	CxxExpression *make_global_expression(CxxIsTemplate isTemplate, CxxDeleteExpression *anExpr);
	CxxExpression *make_global_expression(CxxIsTemplate isTemplate, CxxNewExpression *anExpr);
	CxxName *make_global_id(CxxIsTemplate isTemplate, CxxName *nestedId);
	CxxStatement *make_goto_statement(CxxName *aName);
	CxxExpression *make_greater_equal_expression(CxxExpression *leftExpr, CxxExpression *rightExpr);
	CxxExpression *make_greater_than_expression(CxxExpression *leftExpr, CxxExpression *rightExpr);
	CxxHandler *make_handler(CxxExceptionDeclaration *exceptionDeclaration, CxxStatement *aStatement);
	CxxHandlers *make_handlers(CxxHandlers *aList, CxxHandler *anElement);
	CxxStatement *make_if_statement(CxxCondition *testExpr, CxxStatement *trueStmt, CxxStatement *falseStmt);
	CxxDeclaration *make_include_declaration(CxxExpression *aString, CxxUtility *aUtility);
	CxxExpression *make_inclusive_or_expression(CxxExpression *leftExpr, CxxExpression *rightExpr);
//  CxxExpression *make_index_cast_expression(CxxExpression *aCast, CxxExpression *anExpr);
	CxxSimpleTypeParameter *make_init_simple_type_parameter(CxxSimpleTypeParameter *templateParameters, CxxExpression *anExpr);
	CxxTemplatedTypeParameter *make_init_templated_parameter(CxxTemplatedTypeParameter *typeParameter, CxxName *aName);
	CxxInitializerClauses *make_initializer_clauses(CxxInitializerClauses *aList, CxxInitializerClause *anElement);
	CxxInitializerClause *make_initializer_expression_clause(CxxExpression *anExpr);
	CxxInitializerClause *make_initializer_list_clause(CxxInitializerClauses *aList);
	CxxExpression *make_init_expression(CxxExpression *anExpr);
	CxxDeclSpecifierId *make_inline_in_implementation();
	CxxDeclSpecifierId *make_inline_in_interface();
	CxxFileId *make_input_file(CxxFileId *fileId);
	CxxExpression *make_integer_literal_expression(CxxIntegerLiteral *aLiteral);
	CxxStatement *make_label_statement(CxxName *aLabel, CxxStatement *aStmt);
	CxxExpression *make_less_equal_expression(CxxExpression *leftExpr, CxxExpression *rightExpr);
	CxxExpression *make_less_than_expression(CxxExpression *leftExpr, CxxExpression *rightExpr);
	CxxLine *make_line();
	CxxDeclaration *make_lined_declaration(CxxDeclaration *aDeclaration, CxxLine *aLine);
	CxxStatement *make_lined_statement(CxxStatement *aStatement, CxxLine *aLine);
	CxxToken *make_lined_token(CxxToken *aToken, CxxLine *aLine);
	CxxName *make_linkage_specifier(CxxStrings *aString, CxxDeclaration *aDeclaration);
	CxxExpression *make_logical_and_expression(CxxExpression *leftExpr, CxxExpression *rightExpr);
	CxxExpression *make_logical_or_expression(CxxExpression *leftExpr, CxxExpression *rightExpr);
	CxxMemInitializer *make_mem_initializer(CxxName *aName, CxxExpression *anExpr);
	CxxMemInitializers *make_mem_initializers(CxxMemInitializers *aList, CxxMemInitializer *anElement);
	CxxMemberDeclarations *make_member_declarations(CxxMemberDeclarations *aList, CxxDeclaration *aDeclaration);
	CxxExpression *make_meta_assignment_expression(CxxExpression *leftExpr, CxxToken *assOp, CxxToken *rightExpr);
	CxxBaseSpecifier *make_meta_base_specifier(CxxBaseSpecifier *baseSpecifier);
	CxxMetaType *make_meta_built_in_type(CxxBuiltInId *aName);
	CxxMetaClass *make_meta_class(CxxName *metaClass, CxxBaseSpecifiers *baseSpecifiers, CxxDeclarations *aList);
	CxxMetaFunction *make_meta_function(char isTwiddle, CxxExpression *anExpr, CxxTokenStatements *aBody);
	CxxDeclaration *make_linkage_specification(CxxName *aName);
	CxxDeclaration *make_meta_declaration(CxxExpression *anExpr);
//  CxxMetaInitializer *make_meta_initializer(CxxName *aName, CxxExpression *anExpr);
//  CxxMetaInitializers *make_meta_initializers(CxxMetaInitializers *aList, CxxToken *anElement);
	CxxStatement *make_meta_statement(CxxStatement *aStatement);
	CxxMetaType *make_meta_type(CxxName *aName);
	CxxExpression *make_minus_expression(CxxExpression *anExpr);
	CxxExpression *make_modulus_expression(CxxExpression *leftExpr, CxxExpression *rightExpr);
	CxxExpression *make_multiply_expression(CxxExpression *leftExpr, CxxDeclarator *aDeclarator, CxxExpression *rightExpr);
	CxxName *make_name(CxxName *aName);
	CxxName *make_name_expression(CxxName *aName);
	CxxDeclaration *make_namespace_alias_definition(CxxName *aName, CxxName *forId);
	CxxDeclaration *make_namespace_declaration(CxxName *aName);
	CxxName *make_namespace_definition(CxxName *aName, CxxDeclarations *aDeclaration);
	CxxDeclarator *make_nested_declarator(CxxName *aName, CxxDeclarator *aDeclarator);
	CxxName *make_nested_id(CxxName *nestingId, CxxName *nestedId);
	CxxName *make_nested_scope(CxxName *nestingId);
	CxxNewExpression *make_new_expression(CxxParameters *aPlace, CxxParameters *aType, CxxExpression *anInit);
	CxxNewExpression *make_new_type_id_expression(CxxParameters *aPlace, CxxExpression *aType, CxxExpression *anInit);
	CxxDeclSpecifierId *make_not_const();
	CxxExpression *make_not_equal_expression(CxxExpression *leftExpr, CxxExpression *rightExpr);
	CxxExpression *make_not_expression(CxxExpression *anExpr);
	CxxDeclSpecifierId *make_not_inline();
	CxxDeclSpecifierId *make_not_static();
	CxxDeclSpecifierId *make_not_virtual();
	CxxBaseSpecifier *make_not_virtual_base_specifier(CxxBaseSpecifier *baseSpecifier);
	CxxDeclSpecifierId *make_not_volatile();
	CxxExpression *make_number_literal_expression(CxxExpression *anExpr);
	CxxExpression *make_object_scope_expression(CxxExpression *anExpr, CxxSubspace *aSubspace);
	CxxName *make_operator_add_id();
	CxxName *make_operator_arrow_id();
	CxxName *make_operator_arrow_star_id();
	CxxName *make_operator_ass_add_id();
	CxxName *make_operator_ass_bit_and_id();
	CxxName *make_operator_ass_bit_or_id();
	CxxName *make_operator_ass_div_id();
	CxxName *make_operator_ass_id();
	CxxName *make_operator_ass_mod_id();
	CxxName *make_operator_ass_mul_id();
	CxxName *make_operator_ass_shl_id();
	CxxName *make_operator_ass_shr_id();
	CxxName *make_operator_ass_sub_id();
	CxxName *make_operator_ass_xor_id();
	CxxName *make_operator_bit_and_id();
	CxxName *make_operator_bit_not_id();
	CxxName *make_operator_bit_or_id();
	CxxName *make_operator_call_id();
	CxxName *make_operator_comma_id();
	CxxName *make_operator_dec_id();
	CxxName *make_operator_delete_id();
	CxxName *make_operator_div_id();
	CxxName *make_operator_eq_id();
	CxxName *make_operator_function_id(CxxName *operatorId);
	CxxName *make_operator_ge_id();
	CxxName *make_operator_gt_id();
	CxxName *make_operator_inc_id();
	CxxName *make_operator_index_id();
	CxxName *make_operator_le_id();
	CxxName *make_operator_log_and_id();
	CxxName *make_operator_log_not_id();
	CxxName *make_operator_log_or_id();
	CxxName *make_operator_lt_id();
	CxxName *make_operator_mod_id();
	CxxName *make_operator_mul_id();
	CxxName *make_operator_ne_id();
	CxxName *make_operator_new_id();
	CxxName *make_operator_shl_id();
	CxxName *make_operator_shr_id();
	CxxName *make_operator_sub_id();
	CxxName *make_operator_xor_id();
	CxxParameters *make_parameters(CxxParameters *aList, CxxParameter *anElement);
	CxxParenthesised *make_parenthesised(CxxParameters *aList, CxxCvQualifiers *cvQualifiers, CxxExceptionSpecification *exceptionSpecification);
	CxxExpression *make_plus_expression(CxxExpression *anExpr);
	CxxPointerDeclarator *make_pointer_declarator();
	CxxExpression *make_pointer_expression(CxxDeclarator *aDeclarator, CxxExpression *anExpr);
//  CxxPosition *make_position(CxxPosition *aName);
//  CxxFunctionBody *make_position_function_block(CxxFunctionBody *functionBody, CxxPosition *aPosition);
	CxxExpression *make_post_decrement_expression(CxxExpression *anExpr);
	CxxExpression *make_post_increment_expression(CxxExpression *anExpr);
	CxxExpression *make_pre_decrement_expression(CxxExpression *anExpr);
	CxxExpression *make_pre_increment_expression(CxxExpression *anExpr);
	CxxName *make_pseudo_destructor_id(CxxBuiltInId *aScope, CxxBuiltInId *aName);
	CxxDeclSpecifierId *make_pure_virtual();
	CxxDeclarator *make_reference_declarator();
	CxxExpression *make_reinterpret_cast_expression(CxxExpression *aType, CxxExpression *anExpr);
	CxxStatement *make_return_statement(CxxExpression *anExpr);
	CxxExpression *make_scoped_pointer_expression(CxxExpression *aScope, CxxDeclarator *aDeclarator, CxxExpression *anExpr);
	CxxSegment *make_segment(CxxSegment *aSegment);
	CxxFunctionBody *make_segment_function_block(CxxFunctionBody *functionBody, CxxSegment *aSegment);
	CxxDeclSpecifierId *make_set_template_decl_specifier(CxxDeclSpecifierId *aName);
	CxxDeclaration *make_set_template_declaration(CxxDeclaration *aDeclaration);
	CxxExpression *make_set_template_expression(CxxExpression *anExpr);
	CxxName *make_set_template_id(CxxName *aName);
	CxxName *make_set_template_name(CxxName *aName);
	CxxExpression *make_shift_left_expression(CxxExpression *leftExpr, CxxExpression *rightExpr);
	CxxExpression *make_shift_right_expression(CxxExpression *leftExpr, CxxExpression *rightExpr);
	CxxDeclaration *make_simple_declaration(CxxExpression *anExpr);
	CxxExpression *make_sizeof_expression(CxxExpression *anExpr);
	CxxStatements *make_statements(CxxStatements *, CxxStatement *aStmt);
	CxxExpression *make_static_cast_expression(CxxExpression *aType, CxxExpression *anExpr);
	CxxExpression *make_string_literal_expression(CxxStrings *aString);
	CxxSubspace *make_subspace(CxxSubspace *aSubspace, CxxDeclaration *anElement);
	CxxExpression *make_subtract_expression(CxxExpression *leftExpr, CxxExpression *rightExpr);
	CxxStatement *make_switch_statement(CxxCondition *testExpr, CxxStatement *aStmt);
	CxxMetaFunction *make_syntax_macro_definition(CxxMetaType *metaType, CxxIsExposed isExposed, CxxName *aName, CxxSyntaxMacroParameters *aList, CxxToken *aBody);
	CxxSyntaxMacroParameter *make_syntax_macro_parameter(CxxToken *metaType, CxxIsExposed isExposed, CxxName *aName);
	CxxSyntaxMacroParameters *make_syntax_macro_parameters(CxxSyntaxMacroParameters *aList, CxxSyntaxMacroParameter *anElement);
	CxxTemplateArgument *make_template_argument(CxxParameter *aParameter);
	CxxTemplateArguments *make_template_arguments(CxxTemplateArguments *aList, CxxTemplateArgument *anElement);
	CxxDeclaration *make_template_declaration(CxxTemplateParameters *aList, CxxDeclaration *aDeclaration);
	CxxName *make_template_name(CxxName *aName, CxxTemplateArguments *templateArguments);
//  CxxTemplateParameter *make_templated_template_parameter(CxxTemplateParameter *typeParameter, CxxName *aName);
	CxxTemplatedTypeParameter *make_templated_type_parameter(CxxTemplateParameters *templateParameters, CxxName *aName);
	CxxTemplateParameter *make_template_parameter(CxxParameter *aParameter);
	CxxTemplateParameters *make_template_parameters(CxxTemplateParameters *aList, CxxTemplateParameter *anElement);
	CxxExpression *make_this_expression();
	CxxExpression *make_throw_expression(CxxExpression *anExpr);
	CxxExpression *make_tokens_expression(CxxTokens *someTokens);
	CxxToken *make_tree_argument(CxxToken *aToken);
	CxxTokens *make_tree_arguments(CxxTokens *aList, CxxToken *anElement);
	CxxTokens *make_tree_arguments(CxxTokens *aList, CxxTokens *anotherList);
	CxxExpression *make_tree_array_expression(CxxExpression *anExpr, CxxExpression *indexExpr);
	CxxExpression *make_tree_arrow_expression(CxxExpression *anExpr, CxxName *aName);
	CxxExpression *make_tree_call_expression(CxxExpression *anExpr, CxxTokens *aList);
	CxxExpression *make_tree_dot_expression(CxxExpression *anExpr, CxxName *aName);
	CxxExpression *make_tree_expression(CxxName *aName);
	CxxName *make_tree_id(CxxName *aName);
	CxxExpression *make_tree_pointer_expression(CxxExpression *anExpr);
	CxxTokenStatements *make_tree_statements(CxxTokens *aList, CxxToken *anElement);
	CxxExpression *make_true_expression();
	CxxStatement *make_try_block(CxxStatement *aStatement, CxxHandlers *exceptionHandlers);
	CxxFunctionBody *make_try_function_block(CxxFunctionBody *functionBody, CxxHandlers *exceptionHandlers);
	CxxExpression *make_type1_expression(CxxExpression *functionName, CxxParenthesised *aParenthesis, CxxType1Parameters *type1Parameters);
	CxxTemplateParameter *make_type_template_parameter(CxxSimpleTypeParameter *typeParameter, CxxExpression *typeId);
	CxxExpression *make_typed_expression(CxxName *frontName, CxxExpression *backName);
	CxxName *make_typed_name(CxxName *frontName, CxxName *backName);
	CxxExpression *make_typeid_expression(CxxExpression *aList);
	CxxSimpleTypeParameter *make_typename_type_parameter(CxxName *aName);
	CxxType1Parameters *make_type1_parameters(CxxType1Parameters *aList, CxxParameters *someParameters);
	CxxDeclaration *make_using_declaration(bool isTypename, CxxName *aName);
	CxxDeclaration *make_using_directive(CxxName *aName);
	CxxFunctionBody *make_using_function_block(CxxFunctionBody *functionBody, CxxFileIds *fileIds);
	CxxDeclaration *make_using_implementation_declaration(CxxFileId *fileId);
	CxxDeclaration *make_using_interface_declaration(CxxFileId *fileId);
	CxxUtility *make_utility(CxxUtility *aUtility);
	CxxUtility *make_utility_mode();
	CxxBaseSpecifier *make_virtual_base_specifier(CxxBaseSpecifier *baseSpecifier);
	CxxStatement *make_while_statement(CxxCondition *testExpr, CxxStatement *aStmt);
};

#endif
